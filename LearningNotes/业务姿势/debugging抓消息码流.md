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

