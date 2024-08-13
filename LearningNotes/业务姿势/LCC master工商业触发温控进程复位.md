

## 问题发现

### 背景

-   LCC电站工商业一套代码两个版本通过几种差异化方法在功能上进行区分，但是本质两种产品对应的软件是共bin的；

-   LCC工商业处于过点状态，为保证新开发电站需求不会对工商业造成影响，将工商业拆出分支，电站在master进行开发。master分支的工商业相关代码有接近4个月时间不曾维护；

### 发现

-   工商业过点后，准备收编工商业分支到master，测试发现简单的开启压缩机功能在master的工商业版本会导致特性进程重启；

    -   1、重启过程中无任何异常打印；

    -   2、临终遗言中有对应的记录；

    -   ```cpp
        **************** Exception Info Record By sys ****************
        Exception Time        : 2024-8-2 4:10:23
        Exception Task        : DefSch0100(TaskId = b)
        Exception Signal      : 11
        Exception Signal errno: 0
        Exception Signal code : 2 (SEGV_ACCERR)
        
        Register Contents:
        Reg:    trap_no, Val =  0x0000000e;Reg:    err_code, Val =  0x00000017;
        Reg:    oldmask, Val =  0x00000000;Reg:          r0, Val =  0xa4604c48;
        Reg:         r1, Val =  0x00000001;Reg:          r2, Val =  0x006ce788;
        Reg:         r3, Val =  0xa46a3dc0;Reg:          r4, Val =  0x0051bf53;
        Reg:         r5, Val =  0x00000006;Reg:          r6, Val =  0x00000001;
        Reg:         r7, Val =  0xa3f5e828;Reg:          r8, Val =  0xa3f5eb60;
        Reg:         r9, Val =  0xa647ea18;Reg:         r10, Val =  0xa653e110;
        Reg:         fp, Val =  0xa3f5eafc;Reg:          ip, Val =  0x00000000;
        Reg:         sp, Val =  0xa3f5e828;Reg:          lr, Val =  0x00510753;
        Reg:         pc, Val =  0x005109cc;Reg:        cpsr, Val =  0x80010030;
        Reg: fault_addr, Val =  0xa46a3dc0;
        
        Dump stack when signal occurs,total 1024 Bytes,16Bytes/line.
        0xa3f5e828:  0x00011820 0xa4601870 0x00000000 0x95ad7a00
        0xa3f5e838:  0xa3f5e840 0x00510753 0x00000001 0xa4601870
        0xa3f5e848:  0xa3f5e850 0x00510717 0xa3f5e87c 0xa4601870
        0xa3f5e858:  0xa3f5e860 0x005106ab 0xa3f5e87c 0xa4601870
        0xa3f5e868:  0xa3f5e870 0x005408d7 0xa4601820 0xa4604e50
        0xa3f5e878:  0x00000000 0x00000001 0x3e93e942 0x00000000
        0xa3f5e888:  0x00000000 0x00000000 0xa4600000 0xffffffff
        0xa3f5e898:  0x00005600 0x95ad7a00 0xa3f5e8a8 0x005410eb
        0xa3f5e8a8:  0xa4601820 0xa4604e50 0xa3f5e8b8 0x00540ecf
        0xa3f5e8b8:  0xa4601820 0xa4604e50 0xa3f5e8c8 0x00520fc1
        0xa3f5e8c8:  0xa3f5e8d0 0xa4601814 0x0006e8d8 0x04601814
        0xa3f5e8d8:  0xa3f5e8e0 0x005210d7 0x00060000 0xa4608f50
        0xa3f5e8e8:  0x0006e8f0 0xa4601814 0xa3f5e8f8 0x00526bdd
        0xa3f5e8f8:  0xa3f5e910 0xa4608f50 0x00068f80 0xa4601814
        0xa3f5e908:  0xa3f5e910 0xa4601790 0xa3f5e918 0x0051bf79
        0xa3f5e918:  0xa4601c50 0xa4608f50 0x00060000 0xa4601790
        0xa3f5e928:  0xa3f5e930 0x004ef85b 0x00000000 0xff000000
        0xa3f5e938:  0x00000002 0x006f4f28 0x00000000 0x006f4d40
        0xa3f5e948:  0x00000000 0xa4601790 0xa3f5e964 0x00000001
        0xa3f5e958:  0xa4608f50 0xa4608f80 0xa4608f90 0x006f0000
        0xa3f5e968:  0x00000000 0x95ad7a00 0x004c01d1 0x00000003
        0xa3f5e978:  0xa3f5e988 0x004c6ebf 0x00000000 0xa4602640
        0xa3f5e988:  0xa40d46e4 0x006f4f10 0x0002e9c8 0x00000000
        0xa3f5e998:  0xa3f5e9b0 0x004f6fff 0x00000000 0xa3f5e9a8
        0xa3f5e9a8:  0xa3f5e9b0 0xa4602d04 0xa40d46e4 0x006f4e54
        0xa3f5e9b8:  0x00000000 0x000e2d00 0xa4602640 0x004bebf1
        0xa3f5e9c8:  0x00000000 0x95ad7a00 0xa3f5e9e8 0x004be923
        0xa3f5e9d8:  0xa3f5ea24 0x0001ea14 0xa40d46e4 0x006f5610
        0xa3f5e9e8:  0xa3f5ea18 0x0001003c 0xa40d46e4 0x006f5610
        0xa3f5e9f8:  0xa4602d00 0x00000000 0x00000000 0x95ad7a00
        0xa3f5ea08:  0xa3f5ea18 0x004be82d 0xa3f5ea26 0x00000000
        0xa3f5ea18:  0xa40d46e4 0x006f5610 0x00000000 0x003c0001
        0xa3f5ea28:  0xa4602094 0x95ad7a00 0x00000000 0xb6da088c
        0xa3f5ea38:  0xa3f5ea40 0x00578c81 0xa40d46e4 0xa647ea18
        0xa3f5ea48:  0xa3f5ea58 0x00578f69 0xa6477914 0x00000009
        0xa3f5ea58:  0xa40d46e4 0xa647ea18 0x00000000 0xa40d46e4
        0xa3f5ea68:  0xa3f5ea80 0x00579099 0x00000000 0xa6476b48
        0xa3f5ea78:  0x00000000 0xb6da088c 0xa40d46e4 0xa647ea18
        0xa3f5ea88:  0x00030001 0x00000000 0xa3f5eaa0 0x005786d5
        0xa3f5ea98:  0x7231e21f 0x00000005 0xa647ea18 0xa40d46e4
        0xa3f5eaa8:  0x00000000 0xa647ea18 0x00000000 0xb6b8f23c
        0xa3f5eab8:  0xa3f5eafc 0xa3f5eafc 0xa3f5eb5c 0xa653a090
        0xa3f5eac8:  0x0001f35c 0x00000000 0xb6dadce4 0xa40d46e4
        0xa3f5ead8:  0x00000005 0xb6da088c 0xa40d46e4 0x00000000
        0xa3f5eae8:  0xb6b8f118 0xa6530490 0xb6db63ac 0x00000000
        0xa3f5eaf8:  0xa3f5ebc4 0xb6b92dac 0xa3f5eb98 0xa3f5eb5c
        0xa3f5eb08:  0x1cfc1c48 0x0000039e 0x00000000 0xa6451ac8
        0xa3f5eb18:  0x00000000 0x00000000 0x00000000 0x00000001
        0xa3f5eb28:  0xa3f5eb90 0xa3f5eb94 0x00000000 0xb6db6350
        0xa3f5eb38:  0xa3f5eb8c 0xa653e110 0xa6530160 0xa653a090
        0xa3f5eb48:  0x00000000 0x8000104b 0xa6451ac8 0x00000000
        0xa3f5eb58:  0x00000000 0x00000000 0x00000001 0x00000001
        0xa3f5eb68:  0x00000001 0x00000000 0x00000000 0x00000000
        0xa3f5eb78:  0x00000000 0x95ad7a00 0x00000000 0x00000000
        0xa3f5eb88:  0x00000000 0x00000175 0x00000004 0x00000000
        0xa3f5eb98:  0x00000002 0x95ad7a00 0xa3f5ebcc 0xa653e110
        0xa3f5eba8:  0xa6530160 0xa6530490 0xb6da088c 0xa6530374
        0xa3f5ebb8:  0x00000008 0xb628165b 0xa3f5ec04 0xb6b94678
        0xa3f5ebc8:  0xa3f5ec04 0x00000000 0xa6530174 0xb6b93950
        0xa3f5ebd8:  0xa653e110 0x95ad7a00 0xb6b9372c 0xa6530490
        0xa3f5ebe8:  0xb6dad330 0x0000000b 0xa6530160 0x00000000
        0xa3f5ebf8:  0x00000008 0xb628165b 0xa3f5ec4c 0xb6b94440
        0xa3f5ec08:  0xa3f5ec24 0xb6cd82a4 0xa644a9a8 0xb6da088c
        0xa3f5ec18:  0x00000000 0x00000000 0xa644aa08 0xb6a08628
        0xa3f5ec28:  0x00000000 0x95ad7a00 0xa644a9a8 0xb6b94518
        
        Show CallStack
        /app_run/app_bin/apploadbin/temp_sch(+0x12218c)[0x59118c]
        /app_run/app_bin/apploadbin/temp_sch(+0x1222b0)[0x5912b0]
        /app_run/app_bin/apploadbin/temp_sch(+0x12220c)[0x59120c]
        /lib/libdopra_4.2.1.so(sigcapHookListHandler+0x16c)[0xb6a15a28]
        /lib/libdopra_4.2.1.so(sigcapHandler+0x54)[0xb6a1535c]
        /lib/libc.so.6(__default_rt_sa_restorer+0x0)[0xb634a7c0]
        /app_run/app_bin/apploadbin/temp_sch(+0xa19cc)[0x5109cc]
        /app_run/app_bin/apploadbin/temp_sch(+0xa1752)[0x510752]
        /app_run/app_bin/apploadbin/temp_sch(+0xa1716)[0x510716]
        /app_run/app_bin/apploadbin/temp_sch(+0xa16aa)[0x5106aa]
        /app_run/app_bin/apploadbin/temp_sch(+0xd18d6)[0x5408d6]
        /app_run/app_bin/apploadbin/temp_sch(+0xd20ea)[0x5410ea]
        /app_run/app_bin/apploadbin/temp_sch(+0xd1ece)[0x540ece]
        /app_run/app_bin/apploadbin/temp_sch(+0xb1fc0)[0x520fc0]
        /app_run/app_bin/apploadbin/temp_sch(+0xb20d6)[0x5210d6]
        /app_run/app_bin/apploadbin/temp_sch(+0xb7bdc)[0x526bdc]
        /app_run/app_bin/apploadbin/temp_sch(+0xacf78)[0x51bf78]
        /app_run/app_bin/apploadbin/temp_sch(+0x8085a)[0x4ef85a]
        /app_run/app_bin/apploadbin/temp_sch(+0x57ebe)[0x4c6ebe]
        /app_run/app_bin/apploadbin/temp_sch(+0x87ffe)[0x4f6ffe]
        ```
    
    -   3、该问题有必现条件；

### 问题代码

```c++
VOS_UINT32 LogicCompSysStateNormRun::CalcLastCompCtrlInfo(LogicCompSysCtrlData &compSysData, VOS_FLOAT &lastCtrlPerc,
    VOS_FLOAT &ratedCapacity)
{
    auto compModule = compSysData.compModule; // 出现了析构导致问题，并非是出作用域释放
    // auto &compModule = compSysData.compModule; // 没问题
    // LogicCompModule compModule = compSysData.compModule; // 没问题
    VOS_FLOAT lastOutCap = 0.0f;
    VOS_FLOAT ratedCap = 0.0f;

    if ((compModule.GetCapacity(COMPRESSOR_MODULE_CTRL_CAP, lastOutCap) != VOS_OK) ||
        (compModule.GetCapacity(COMPRESSOR_MODULE_RATED_CAP, ratedCap) != VOS_OK)) {
        EMAP_LOG(COMP_MODULE_ID_TEMP_CTRL_SCHEDULE, EMAP_PRINT_LEVEL_ERROR, "comp module get capacity err");
        return VOS_ERR;
    }

    if (FLOAT_EQ_ZERO(ratedCap)) {
        EMAP_LOG(COMP_MODULE_ID_TEMP_CTRL_SCHEDULE, EMAP_PRINT_LEVEL_ERROR, "comp capacity err");
        return VOS_ERR;
    }

    lastCtrlPerc = lastOutCap / ratedCap;
    ratedCapacity = ratedCap;
    return VOS_OK;
}
```

## 定位过程

-   最初猜测只是简单的踩内存问题，所以通过临终遗言观察程序中之前的调用栈来寻找可能的踩内存位置；

-   经过gdb调试后发现该位置（指针数组）并未出现越界、重新赋值等操作。但新的发现是，该指针数组存储的一些列派生类的虚表在进程复位前消失；

    -   ![image-20240802172627670](http://image.huawei.com/tiny-lts/v1/images/a5c7af53a92a407ae34377dfd25fdf98_2438x894.png)

-   虚表消失大概有两种可能：
    -   1、基类被踩内存（分配了新的内存在该位置），导致对象的内存布局被破坏，虚表指针（vptr）不再指向正确的虚表，用基类指针承载的派生类对象进行调用时导致一系列的内存互踩；
    -   2、该类被释放，在当时的惯性思维下我们都认为这是最不可能发生的，因为正常情况下析构的条件是：1)逻辑初始化失败（实际逻辑已经正常运行）；2)main函数结束（实际main函数异常退出，进程异常重启）；

-   花费了大量的时间寻找周边类/结构体new时可能导致的问题，使用的定位手段包括但不限于gdb、重载new/delete、asan等等；

-   平台mamengyu建议从类被释放的方面入手。定位发现a类析构，b类析构，c结构体未析构，d类未析构，层级关系如下：

    -   ![image-20240802171110821](http://image.huawei.com/tiny-lts/v1/images/5e15fd74940d4e4919ba9ce484728ba3_650x398.png)

    -   可以确定，该问题是由运行逻辑中的内存正常释放导致的野指针踩空导致；

    -   使用gdbserver挂载调试复现，在析构函数中打断点，断住之后backtrace(bt)，逐行分析可能的释放位置，定位到是将引用赋值给auto类型时，左侧对象执行析构，释放掉指针数组的内容，原本类中结构体c中存储的类b中的指针数组指向的类被释放，维护使用指针处继续使用空指针进行操作，导致踩空；

```cpp
    1145        EMAP_LOG(4171, 5, "[LogicCompModuleDmdCtrl] destructor");
    (gdb) bt
    #0  LogicCompModuleDmdCtrl::~LogicCompModuleDmdCtrl (this=0xa4704c48, __in_chrg=<optimized out>)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_module/logic_comp_module_state/logic_comp_module_dmd_ctrl.cpp:1145
    #1  0x00524fda in LogicCompModuleDmdCtrl::~LogicCompModuleDmdCtrl (this=0xa4704c48, __in_chrg=<optimized out>)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_module/logic_comp_module_state/logic_comp_module_dmd_ctrl.cpp:1146
    #2  0x0051fe52 in LogicCompModule::ReleaseResource (this=0xa41fc780)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_module/logic_comp_module.cpp:50
    #3  0x0051fdb4 in LogicCompModule::~LogicCompModule (this=0xa41fc780, __in_chrg=<optimized out>)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_module/logic_comp_module.h:123
    #4  0x005515f8 in LogicCompSysStateNormRun::CalcLastCompCtrlInfo (this=0xa4704e50, compSysData=..., lastCtrlPerc=@0xa41fc7e4: 0, ratedCapacity=@0xa41fc7e0: 2.5)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_state/logic_comp_sys_state_norm_run.cpp:180
    #5  0x0055143e in LogicCompSysStateNormRun::CalcCompModuleTempPidDmd (this=0xa4704e50, compSysData=..., routeCtrlInfo=..., dmdCalcPid=...)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_state/logic_comp_sys_state_norm_run.cpp:162
    #6  0x00551248 in LogicCompSysStateNormRun::CalcCompModuleCoolDmd (this=0xa4704e50, compSysData=..., routeCtrlInfo=..., dmdCalcPid=...)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_state/logic_comp_sys_state_norm_run.cpp:122
    #7  0x0055199a in LogicCompSysStateNormRun::CalcCompCoolCtrlInfo (this=0xa4704e50, compSysData=..., compModuleCtrl=...)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_state/logic_comp_sys_state_norm_run.cpp:273
    #8  0x00551846 in LogicCompSysStateNormRun::ProcCompDmdCtrl (this=0xa4704e50, compSysData=...)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_state/logic_comp_sys_state_norm_run.cpp:242
    #9  0x005520ea in LogicCompSysStateNormRun::ProcDmdCtrl (this=0xa4704e50, compSysData=...)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_state/logic_comp_sys_state_norm_run.cpp:466
    #10 0x00551ece in LogicCompSysStateNormRun::ProcCtrl (this=0xa4704e50, compSysData=...)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_state/logic_comp_sys_state_norm_run.cpp:404
    #11 0x00531fc0 in LogicCompSysEquipGroupProcCtrl::ProcCompSysState (this=0xa4701814)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_equip_group_proc_ctrl.cpp:418
    #12 0x005320d6 in LogicCompSysEquipGroupProcCtrl::ProcCtrl (this=0xa4701814, ctrlTypeNum=6, ctrlInfo=0xa4708f50)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_equip_group_proc_ctrl.cpp:451
    #13 0x00537bdc in LogicCompSysEquipGroupProcCtrlWithCompHeat::ProcCtrl (this=0xa4701814, ctrlTypeNum=6, ctrlInfo=0xa4708f50)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_equip_group_proc_ctrl_with_comp_heat.cpp:69
    #14 0x0052cf78 in LogicCompSysEquipGroupImpl::ProcCtrl (this=0xa4701790, ctrlTypeNum=6, ctrlInfo=0xa4708f50)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_equip_group/e_store/logic_comp_sys_equip_group/logic_comp_sys_equip_group_impl.cpp:42
    #15 0x0050085a in LogicCompSysCtrlBase::Ctrl (this=0x705f28 <CreateSubStateDehumOffCabCoolOffBatActiveCool(LogicObjectType)::stateDehumOff+24>, ctrlMode=0, route1DemandId=2, route2DemandId=65280)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_mode/e_store/mode_utility/equip_group_ctrl/logic_comp_sys_equip_group_ctrl/logic_comp_sys_equip_group_ctrl.cpp:33
    #16 0x004d7ebe in DehumOffCabCoolOffBatActiveCoolWithIncab::Proc (this=0x705f10 <CreateSubStateDehumOffCabCoolOffBatActiveCool(LogicObjectType)::stateDehumOff>, recvMsg=0xa46728e4)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_mode/e_store/auto_mode/dehum_off_cab_cool_off_bat_active_cool/dehum_off_cab_cool_off_bat_active_cool_with_incab.cpp:25
    #17 0x00507ffe in LogicModeCtrlBase::Proc (this=0x705e54 <CreateAutoMode(LogicObjectType)::autoMode>, recvMsg=0xa46728e4)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_mode/logic_mode_ctrl_base/logic_mode_ctrl_base.cpp:65
    #18 0x004cf922 in LogicModeMgrBase::ProcModeSwitch (this=0x706610 <LogicModeMgr::GetInstance()::logicModeMgr>, recvMsg=0xa46728e4, nextMode=LOGIC_MODE_TYPE_AUTO, nextState=LOGIC_SUB_STATE_INVALID)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_mode_mgr/logic_mode_mgr_base/logic_mode_mgr_base.cpp:104
    #19 0x004cf82c in LogicModeMgrBase::ProcMsg (this=0x706610 <LogicModeMgr::GetInstance()::logicModeMgr>, recvMsg=0xa46728e4)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/logic_mode_mgr/logic_mode_mgr_base/logic_mode_mgr_base.cpp:86
    #20 0x00589c80 in TempCtrlScheduleInstance::ProcLogicSchedule (this=0xa657ea18, compMsg=0xa46728e4)
    at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/temp_ctrl_schedule_instance.cpp:222
    #21 0x00589f68 in TempCtrlScheduleInstance::OnCompTimer (this=0xa657ea18, compMsg=0xa46728e4) at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/temp_ctrl_schedule_instance.cpp:315
    #22 0x0058a098 in TempCtrlScheduleInstance::OnCompMsg (this=0xa657ea18, compMsg=0xa46728e4) at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/temp_ctrl_schedule_instance.cpp:360
    #23 0x005896d4 in TempCtrlScheduleCompMsgProc (msg=0xa46728e4, instancePtr=0xa657ea18) at /usr1/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/src/temp_ctrl_schedule_comp.cpp:50
    #24 0xb6c3623c in RTF_MsgProcessCbk () from target:/lib/libdopra_4.2.1.so
    #25 0xb6c39dac in rtfScmMessageSchedule () from target:/lib/libdopra_4.2.1.so
    #26 0xb6c3b678 in rtfScmCompScheKernelEntryFifo () from target:/lib/libdopra_4.2.1.so
    #27 0xb6c3b440 in rtfScmCompScheDefaultEntry () from target:/lib/libdopra_4.2.1.so
    #28 0xb6aad0c8 in VosTskAllTaskEntry () from target:/lib/libdopra_4.2.1.so
    #29 0xb643511c in ?? () from target:/lib/libc.so.6
    #30 0xb64b367c in ?? () from target:/lib/libc.so.6
    Backtrace stopped: previous frame identical to this frame (corrupt stack?)
```

## 遗留问题（需要进一步研究证明）：

-   1、为何类向auto初始化赋值时会调用析构函数；
-   2、为何类向类本身类型初始化赋值时不会调用析构函数；
-   3、调用析构函数之后再次访问该类的方法为什么不会报错（是因为中间析构的是临时的类变量？）；
    -   如图：在析构函数中添加打印，释放的内存就是后续赋值给auto的类中的指针数组，且在析构函数执行到 `}` 时打印对象本身，指针数组已经被释放：
	    
    -   ![image-20240807162538327](http://image.huawei.com/tiny-lts/v1/images/7c69ce2f507584aaf44e104e298729cf_267x119.png)
	-   ![image-20240807162548464](http://image.huawei.com/tiny-lts/v1/images/31a2aa46ffc73646724b603dcec77275_676x302.png)
	-   ![image-20240807162510159](http://image.huawei.com/tiny-lts/v1/images/9678b65b719e71ba75a692a2fa391804_1175x21.png)
	-   ![image-20240807162644414](http://image.huawei.com/tiny-lts/v1/images/dd95301a23900d85a5eb507722fe8a9e_2066x349.png)


## 定位手段

### 临终遗言

-   `/log/sys_log/fault_manager_except_sys_info_<特性进程名>.emap`
    -   ![image-20240802174906039](http://image.huawei.com/tiny-lts/v1/images/c56dba36b2cc8c6d20bb5984d5e92d34_759x548.png)

-   解压服务器上 `${project_root}/output/luna_tms_2000/rtos_a7/debug` 目录下 `debug.tar.gz` 得到 `debug` 文件夹，进入后可以看到各个包含全部符号表的组件bin文件，可以通过 `gdb` 调试，也可以 `nm` 查看符号表，也可以 `add2line -e <组件名> <临终遗言中调用栈所示地址偏移>` 查看具体的代码行信息；

### [gdbserver](https://dbox.huawei.com/detaildocs?oid=DC%3Awt.doc.WTDocument%3A6743375_PMD25403ZH)

-   对于嵌入式c++资源受限的机器，烧录的软件一般不包含符号表，不便于使用gdb，可以烧录未优化符号的软件版本，但是读取符号的速度十分缓慢，gdbserver-client的形式将调试负担转移到客户端，这样就可以通过高性能的主机进行调试；

- 服务端（单板）

    - gdbserver将附加到需要调试的进程上 `/home/gdbserver :<port> --attach $(pidof <进程名>)`

- 客户端（主机）

    - 解压出编译后带有全部符号的软件 `cd ${project_root}/output/luna_tms_2000/rtos_a7/debug; tar -xvzf ./debug.tar.gz; cd debug`；

    - 使用何种版本的gdb取决于编译时工具链使用的是编译器前缀，可以在 `${project_root}/PublicProduct/LCC/cmake/superbuild/CMakeLists.txt` 下找到所使用的工具链前缀:

        - ```cmake
            # 工具链列表
            set(CMAKE_TOOLCHAIN_PREFIX arm-linux-gnueabi_tool_chain)
            ```

    - `arm-openstlinux_weston-linux-gnueabi-gdb ./temp_sch` 进入gdb调试cli

    - `target remote <ip>:<port>` 连接目标设备的gdbserver

    - 开始调试

### [gdb-strip](https://dbox.huawei.com/detaildocs?oid=DC%3Awt.doc.WTDocument%3A6743375_PMD25395ZH)

-   精简版的gdb，可以运行在单板上，一般缺少符号的app用处不大
-   **gdb-strip 缺少so库** `libreadline.so.8` 、 `libtinfo.so.5` 、 `libexpat.so.1`:
    -   将压缩包 `lib` 中的so库文件拷贝到单板的 `/lib` 目录下
-   `/home/gdb-strip /app_run/app_arm/<app_name>` 开始调试

### asan

-   详见 [单板级ASAN部署](https://codehub-y.huawei.com/Energy_Manifest/PublicProduct/LCC/LCC_Manifest/wiki?categoryId=8&sn=WIKI202404153333233)

-   `./local_compile.sh luna_tms_2000 rtos_a7 asan` 构建asan版本，进程出错后会在 `/log/sys_log/asan` 目录下生成报告

### 内存隔离

-   受emap os限制，暂时无法操作
