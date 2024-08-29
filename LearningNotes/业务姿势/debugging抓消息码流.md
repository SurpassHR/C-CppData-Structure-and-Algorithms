### 相关命令 `rp`、`chl`

#### 抓取 `app_arm` 码流

![image-20240525094528420](http://image.huawei.com/tiny-lts/v1/images/819ff5489162b5c57333706312a6797c_924x763.png)

-   `tty`: Linux系统中的文本输入输出接口，是一个虚拟终端。

    -   `/dev/pts/x`: 第x个虚拟终端
    -   `/dev/ttySx`: 第x个串行端口
    -   举例为第0个虚拟终端

![image-20240525094757804](http://image.huawei.com/tiny-lts/v1/images/c6e121496f91b752176f88b6d358c62a_187x31.png)

-   `debugging` 命令 `rp`: 将进程打印重定向到虚拟终端，`rp 0 <tty_id> 1`
-   `debugging` 命令 `chl`: 更改码流打印级别，`chl 4171 1`

#### 抓取 `can` 码流

-   在 `can` 移动到协核之后，抓取码流目前只能通过抓取 `can` 与设备管理的通信消息码流来过滤
    -   修改设备管理的打印级别 `chl 1 1`
    -   重定向 `app_arm` 进程打印到 `tty_id` `rp 0 <tty_id> 1`

### 抓取指定设备的modbus码流

-   存在modbus设备基类，使用 `modbus_master.cpp` 统一接口进行读寄存器、写寄存器操作。
-   直接修改 `SendModbusReadRegMsg(ModbusData *modbusData, ModbusMsgInfo *msgInfo)` (读寄存器接口)过滤需要的modbus总线地址/设备地址/寄存器地址。

```c++
// 增加打印函数
#include <iostream>
#include <iomanip>
#include <sstream>
VOS_VOID printMemoryAsHex(const VOS_UINT8* data, VOS_UINT32 length) {
    std::ostringstream oss;
    for (VOS_UINT32 i = 0; i < length; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]);
        if (i < length - 1) {
            oss << " ";
        }
    }
    EMAP_LOG(0, EMAP_PRINT_LEVEL_EVENT, "sendMsg: %s", oss.str().c_str());
}

// 在消息体完成构造之后打印
static VOS_UINT16 SendModbusReadRegMsg(ModbusData *modbusData, ModbusMsgInfo *msgInfo)
{
    // 申请消息内存（消息净荷长度是13字节，包含超时时间）
    EMAP_MSG_S *msg = EMAP_MsgAlloc(msgInfo->srcId, msgInfo->msgType, msgInfo->seqNo, 13);
    if (msg == nullptr) {
        return VOS_ERR;
    }

    VOS_UINT8 *msgText = reinterpret_cast<VOS_UINT8 *>(msg) + SIZEOF_EMAP_MSG_S;

	// 构造消息体
    // ...

    // 打印条件
    if ((modbusData->slaveAddr == 0x1) && (modbusData->regAddr == 0x0E08) && (msgInfo->dstPortId == 0x354)) {
        printMemoryAsHex(reinterpret_cast<VOS_UINT8 *>(msg) + SIZEOF_EMAP_MSG_S, 13);
    }

	// 发送消息
    // ...
}
```

-   写寄存器接口 `SendModbusWriteSingleRegMsg` 、`SendModbusWriteMultiRegMsg` 同理。
