## 下载代码

-   以下指令在编译服务器执行：

```bash
# 新建代码目录
mkdir LCC && cd LCC
# 初始化多仓代码目录
git mm init -u https://codehub-dg-y.huawei.com/Energy_Manifest/PublicProduct/LCC/LCC_Manifest.git -b master -m LCC/dependency.xml -g lcc,llt
```

![image-20230731212811781](http://image.huawei.com/tiny-lts/v1/images/231489faf763ddeb258c616ada31ddec_2072x252.png)

```bash
# 同步库上代码
git mm sync -j32
```

![image-20230731212957985](http://image.huawei.com/tiny-lts/v1/images/7101a4b31ea00f744bf09140728baf18_2071x1169.png)

## 编译代码

-   以下指令在编译服务器执行：

-   假设代码根目录路径为 `${LCC_ROOT}`

```bash
# 进入一键编译脚本目录
cd ${LCC_ROOT}/PublicProduct/LCC/build
# 一键下载依赖 + 编译构建 + 打包程序
bash ./local_compile.sh
```

-   打包好的程序位于 `${LCC_ROOT}/output/LCC.tar.gz`

![image-20230731213157590](http://image.huawei.com/tiny-lts/v1/images/e81d96cd93b972e55b78380095ce3f3d_1087x1178.png)

## 烧录程序

-   以下指令在单板环境执行：

![image-20230731213242268](http://image.huawei.com/tiny-lts/v1/images/c7e4a45c14a33f157cb9253fcc863be2_568x47.png)

```bash
# 一键拷贝tar.gz包
# ${USER_NAME}:编译服务器用户名
# ${SERVER_IP}:编译服务器IP地址
# ${LCC_ROOT}:代码根目录路径
scp -r -C ${USER_NAME}@${SERVER_IP}:${LCC_ROOT}/output/LCC.tar.gz /
# 杀死app_arm + 喂狗
killall -9 keeper app_arm LcdGui web_server snmp_plugin network_srv seceye-agent; watchdog -t 100ms /dev/watchdog
# 清除bin0面已烧写的包
rm -rf /mnt/app_bin0/bin_arm/*
# 解压包到bin0面
tar -xvzf /LCC.tar.gz -C /mnt/app_bin0/bin_arm/
# 重启
reboot
```

-   可能存在烧录监控软件不同导致环境初始化不同的问题，手动初始化环境解决问题

```bash
/mnt/app_bin0/bin_arm/init_env
```

## 附加内容

### 查看单板主程序面

-   以下指令在单板环境执行：

```bash
# 查看单板主程序面
cat /log/sys_log/update/config.kp
# 输出：位于第一行的是主面
# #name  mem(kB) cpu%%     command
# app_arm 128000 100  /mnt/app_bin0/bin_arm/app_arm
# app_arm 128000 100  /mnt/app_bin1/bin_arm/app_arm
```

### 查看单板所处大小网状态

-   以下指令在单板环境执行：

```bash
# 查看当前网管为大/小网网关
cat /mnt/kp/ipdata/gateway
# 查看和配置SSH服务器监听地址
cat /mnt/kp/etc/sshd_config | grep ListenAddress
```

### 在日志打印界面杀掉app_arm

-   以下指令在单板环境执行：

```bash
# 挂起 app_arm 切到后台
## ctrl + z
# 杀掉app_arm喂狗
killall -9 keeper app_arm LcdGui web_server snmp_plugin network_srv seceye-agent; watchdog -t 100ms /dev/watchdog
```

### 修改单板时间和日志打印时间

-   以下指令在单板环境执行：
-   `date -s` 修改系统时间（上下电或重启后恢复到 rtc 的1970年）只能临时使用
-   设置日期与日志打印日期存在几小时的偏差，推测是平台时间管理城市和时区设置问题

```bash
date -s [YYYY.]MM.DD-hh:mm[:ss]
```

![img](http://image.huawei.com/tiny-lts/v1/images/a112b53283746a82e1f8cc953c70ad15_1579x955.png)

-   `hwclock` 修改 rtc 时间（缺少底软实现无法使用）

```bash
# hwclock --help
BusyBox v1.32.1 (2022-07-04 17:05:43 CST) multi-call binary.

Usage: hwclock [-r|--show] [-s|--hctosys] [-w|--systohc] [--systz] [--localtime] [-u|--utc] [-f|--rtc FILE]


Query and set hardware clock (RTC)

        -r      Show hardware clock time
        -s      Set system time from hardware clock
        -w      Set hardware clock from system time
        --systz Set in-kernel timezone, correct system time
                if hardware clock is in local time
        -u      Assume hardware clock is kept in UTC
        --localtime     Assume hardware clock is kept in local time
        -f FILE Use specified device (e.g. /dev/rtc2)
```

-   **结论：** 目前暂时无法设置，只能通过底软接口发送消息实现时间控制，之后可以通过添加信号，在 debugging 中设置时间后同步到 rtc

### tftp 文件传输



-   所需软件 [tftpd64.464.zip](https://bitbucket.org/phjounin/tftpd64/downloads/tftpd64.464.zip) / [tftpd32.464.zip](https://bitbucket.org/phjounin/tftpd64/downloads/tftpd32.464.zip)
-   将 tftpd32.exe 与需要传输文件放在同一个目录下，打开 tftpd32.exe，本机作为 Server 使用的 IP 地址与你在 cmd 中查看 ipconfig 的结果相同

![image-20230823222357037](http://image.huawei.com/tiny-lts/v1/images/792393dfd22f7bbc79fbe32a392291cc_715x412.png)

-   点击 Show Dir 可以显示可以传输文件的列表，点击 Copy 快速拷贝文件名

![image-20230823222528794](http://image.huawei.com/tiny-lts/v1/images/eca8683eb2446aa94ce926b9594bbf5d_480x255.png)

-   在单板执行以下命令完成拷贝

```bash
# 启用 tftp
/etc/init.d/tftputils.sh tftp_status_ON
# 拷贝文件
tftp ${ip_addr} -gr ${file_name} -b 8192
# ${ip_addr}: windows 本机 IP 地址
# ${file_name}: 要拷贝的文件名
# -g: Get File
# -r: Recursively
# -b: Baud Rate
```
