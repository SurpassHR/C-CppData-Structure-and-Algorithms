# eMAP架构串讲

## eMAP

-   EMAP对外发布头文件 `emap_so_xx.h`
-   EMAP消息定义头文件 `emap_so_msg_type_def.h`

## Dopra

-   屏蔽所有的单板差异对上层提供统一的开发框架

## Modbus及几种工业自动化、嵌入式行业常见的通信协议

-   Modbus不仅只有modbus-rtu还有modbus-tcp，都是基于modbus通信协议的变体，rtu适用于串行通信，tcp适用于以太网通信

-   Modbus按照串行通信接口标准分类还可以分为RS-232、RS-485和RS-422标准
    -   232是点对点通信
    -   485和422是多点通信，485适合长距离通信1200m，422适合中距离通信15m
    -   485使用2线实现半双工，使用4线实现全双工
    -   **LCC压缩机将modbus-485协议替换为CAN协议可能出于的考虑因素是：**
        -   CAN协议使用差分信号传输，对于电气干扰抗干扰能力强，modbus使用非差分信号
        -   CAN协议的实时性更好
        -   CAN协议支持数据帧的扩展
        -   CAN协议具有良好的检错和纠错机制，提升传输可靠性
        -   串行通信也就是串口通信
    
-   电力行业常见的几种串行通信协议：
    -   YDN：自定义的通信协议
    -   Modbus-RTU：开放标准的串口通信协议
    -   SMS(Short Message Service)：适用于移动通信的文本消息传输协议，主要用于无线通信
    -   BIN-RTU：自定义的通信协议，类似于Modbus-RTU
    -   MSP：用于微控制器之间的串口通信协议，用于嵌入式系统中进行通信，主从通信

-   几种以太网通信协议：
    -   Modbus-TCP：Modbus协议变体，基于TCP/IP协议，以太网实时通信，支持client-server通信模式
    -   SMTP(Simple Mail Transfer Protocol)：文本协议，最常用的邮件传输协议
    -   SNMP(Simple Network Management Protoco)-UDP：用于管理和监控网络中的设备和系统。它允许网络管理员从远程位置监视网络设备的状态、性能和错误信息，并执行配置更改和故障排除。SNMP 使用 UDP 协议进行通信
    -   BIN-TCP：自定义的二进制数据传输协议，它基于 TCP/IP 协议
    -   UDP(User Datagram Protocol)：提供无连接、不可靠的数据传输。UDP 将数据封装成数据包，以较低的开销在网络上发送。由于它不提供错误检测和重传机制，因此不适合对数据可靠性要求较高的应用，但适用于实时传输和广播通信
    
    