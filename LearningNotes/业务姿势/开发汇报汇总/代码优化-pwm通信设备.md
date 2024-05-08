## 对于使用PWM通信的设备代码重构过程

### 0、背景

-   LCC当前设备中存在多种使用不同通信方式的设备，已知的使用PWM进行输出控制的设备由水泵和风机，因此他们中间在PWM相关信号的获取、速度转换为PWM的计算方面都存在功能重复的部分，本着代码复用的想法，对该代码进行优化；
-   最初想法是受到ACC启发，将水泵和风机分别分为通信风机/水泵和非通信风机/水泵，分别从水泵/风机的基类中派生出通信/非通信的设备子类；
-   但是目前看来非通信风机和非通信水泵不会出现其他的控制方式，所以PWM控制输出类型的设备可单独抽取出一个基类，通信设备依旧继承设备基类（目前没有通信设备）；
-   EMAP设备基类->LCC设备基类->PWM设备基类->PWM设备继承深度过深，1、使得代码类的层级结构变得复杂，代码耦合性增加，对于代码理解和维护造成不便；2、同时每个继承层级都会带来一定的内存开销，增加较多的继承层级会导致虚函数调用链较长，影响运行时性能（查虚函数表）；3、同时也会导致设计僵化，在未来难以根据需求进行进一步更改，增加后续重构的风险；
-   最终的设计是将PWM信号配置、数据计算部分作为功能类抽取，在需要PWM通信的设备中进行复用；

### 1、代码

-   头文件

```C++
// lcc_pwm.h
// 对应占空比-转速图的横纵坐标点
struct SpeedPara {
    VOS_FLOAT speed; // 转速
    VOS_FLOAT duty;  // 占空比
};

// 根据转速曲线得到的占空比-速度坐标点
struct DutyCycleCfg {
    SpeedPara stopCoordPoint;    // 停转坐标点配置
    SpeedPara minCoordPoint;     // 最小转速坐标点配置
    SpeedPara maxCoordPoint;     // 最大转速坐标点配置
    SpeedPara reverseCoordPoint; // 反转转速坐标点配置
};

class LccPwm {
public:
    LccPwm() {}
    virtual ~LccPwm() {}

    VOS_FLOAT CalcPwmDuty(VOS_FLOAT speed);
    VOS_VOID RegDutyCycleCfg(const DutyCycleCfg &dutyCycleCfg);

    static VOS_UINT16 CalcFanSpeedFeedback(VOS_UINT32 capVal, VOS_UINT32 pulseNum, VOS_UINT32 &speedFeedback);

private:
    DutyCycleCfg m_dutyCycleCfg{};
};
```

- 实现

```C++
// lcc_pwm.cpp
VOS_FLOAT LccPwm::CalcPwmDuty(VOS_FLOAT speed)
{
    VOS_FLOAT maxSpeed = m_dutyCycleCfg.maxCoordPoint.speed;
    VOS_FLOAT maxDuty  = m_dutyCycleCfg.maxCoordPoint.duty;
    VOS_FLOAT minSpeed = m_dutyCycleCfg.minCoordPoint.speed;
    VOS_FLOAT minDuty  = m_dutyCycleCfg.minCoordPoint.duty;

    if (FLOAT_LT(speed, 0.0f)) {
        if (!FLOAT_EQ(m_dutyCycleCfg.reverseCoordPoint.duty, static_cast<VOS_FLOAT>(EMAP_INVALID_VALUE_FLOAT))) {
            return m_dutyCycleCfg.reverseCoordPoint.duty;
        } else {
            EMAP_LOG(EMAP_MODULE_ID_MCL_EQUIPMGR, EMAP_PRINT_LEVEL_ERROR, "wrong speed val");
            return m_dutyCycleCfg.stopCoordPoint.duty;
        }
    } else if (FLOAT_EQ(speed, 0.0f)) {
        return m_dutyCycleCfg.stopCoordPoint.duty;
    } else if (FLOAT_LE(speed, minSpeed)) {
        return minDuty;
    } else if (FLOAT_GT(speed, minSpeed) && FLOAT_LT(speed, maxSpeed)) {
        return (speed - minSpeed) * ((maxSpeed - minSpeed) / (maxDuty - minDuty)) + minDuty;
    } else {
        return maxDuty;
    }
}

// 将 速度-占空比 参数注册到成员结构体中
VOS_VOID LccPwm::RegDutyCycleCfg(const DutyCycleCfg& dutyCycleCfg)
{
    // 计算PWM时需要保证最大占空比大于最小占空比，在注册时进行判断
    if (FLOAT_LE(dutyCycleCfg.maxCoordPoint.duty, dutyCycleCfg.minCoordPoint.duty)) {
        EMAP_LOG(EMAP_MODULE_ID_MCL_EQUIPMGR, EMAP_PRINT_LEVEL_ERROR, "maxSpeed equals minSpeed err");
        return;
    }
    m_dutyCycleCfg = dutyCycleCfg;
}

VOS_UINT16 LccPwm::CalcFanSpeedFeedback(VOS_UINT32 capVal, VOS_UINT32 pulseNum, VOS_UINT32 &speedFeedback)
{
    // 除0保护：若每圈脉冲数为0，需检查风机配置是否正确配置，异常返回
    if (pulseNum == 0) {
        speedFeedback = 0;
        EMAP_LOG(EMAP_MODULE_ID_MCL_EQUIPMGR, EMAP_PRINT_LEVEL_ERROR, "fan cfg pulse num err");
        return VOS_ERR;
    }
    // 除0保护：若此时cap信号获得脉冲间时间间距为0，则可以判断风机转子停转，正常返回
    if (capVal == 0) {
        speedFeedback = 0;
        return VOS_OK;
    }

    const VOS_FLOAT microSecsPerMin = 60.0 * 1000000.0; // 每分钟微秒数
    VOS_FLOAT speedVal = microSecsPerMin / (pulseNum * capVal); // 每分钟转速rpm = 每分钟微秒数 / (每圈脉冲个数 * 两脉冲间时间)
    speedFeedback = static_cast<VOS_UINT32>(ROUND(speedVal)); // 转换为整数

    return VOS_OK;
}
```

-   调用

```C++
// non_commu_fan.h
class NonCommuFan : public LccEquipBase {
public:
    NonCommuFan(EMAP_EQUIP_INFO_S &equipInfo, VOS_HANDLE_T equipHandle, const VOS_VOID *equipCfg);
    ~NonCommuFan() override;

    VOS_UINT16 InitEx() override;
    VOS_UINT16 Query() override;
    VOS_UINT16 ProcessPortMsg(EMAP_MSG_S *recvMsg) override;
    VOS_UINT16 SetSigValueToPort(VOS_UINT16 equipId, VOS_UINT16 sigId, VOS_CHAR *sigValue) override;

private:
    ...
    VOS_UINT16 CtrlOutput(VOS_CHAR *sigValue);
    ...

private:
    const FanCfg *m_fanCfg{ nullptr };
    LccPwm m_lccPwm;
    ...
};
```

```C++
// non_commu_fan.cpp
NonCommuFan::NonCommuFan(EMAP_EQUIP_INFO_S &equipInfo, VOS_HANDLE_T equipHandle, const VOS_VOID *equipCfg)
    : LccEquipBase(equipInfo, equipHandle)
{
    m_fanCfg = static_cast<FanCfg const *>(equipCfg);
    if (m_fanCfg == nullptr) {
        EMAP_LOG(EMAP_MODULE_ID_MCL_EQUIPMGR, EMAP_PRINT_LEVEL_ERROR, "equip cfg nullptr err");
    } else {
        m_lccPwm.RegDutyCycleCfg(m_fanCfg->dutyCycleCfg);
    }
}

...

VOS_UINT16 NonCommuFan::CtrlOutput(VOS_CHAR *sigValue)
{
    if (m_fanCfg == nullptr || sigValue == nullptr) {
        EMAP_LOG(EMAP_MODULE_ID_MCL_EQUIPMGR, EMAP_PRINT_LEVEL_ERROR, "nullptr err");
        return VOS_ERR;
    }
    VOS_FLOAT speed = *(reinterpret_cast<VOS_FLOAT *>(sigValue));
    VOS_FLOAT pwm = m_lccPwm.CalcPwmDuty(speed);
    // 10: 水泵频率为1000Hz，故周期为1000μs，PWM值乘10映射到0-1000范围内
    VOS_UINT16 ret = VRL_SetAo(m_fanCfg->vrlCfg.ctrlStateVrlAo, VrlAoType::AO_TYPE_PWM, static_cast<VOS_UINT32>(pwm * 10));
    if (ret != VOS_OK) {
        EMAP_LOG(EMAP_MODULE_ID_MCL_EQUIPMGR, EMAP_PRINT_LEVEL_ERROR, "set ao err, sigId: %#x, ret: %#x", m_fanCfg->vrlCfg.ctrlStateVrlAo, ret);
        return VOS_ERR;
    }

    return ret;
}
```

