## 必要步骤

### 前置工作

-   折腾的原因

![image-20230818141910465](http://image.huawei.com/tiny-lts/v1/images/1276fb60380a4ebdb81698b151799dbf_999x266.png)

-   不使用 docker 的原因
    -   1、虽然部署方便，但是不便于烧写压缩包到单板环境测试
    -   2、docker 启动一段时间后会出现占用100% CPU的问题，且 docker 作为 kernel 进程启动无法被杀死，一旦 CPU 爆炸就只能关闭再重开

-   WSL **Ubuntu20.04**，下载安装：[wsl-auto-setup-下载](https://openx.huawei.com/wsl-auto-setup/download/)
-   docker 自动部署编译环境直接参考：[Wiki: wsl数字能源一键式编译环境指导](https://wiki.huawei.com/domains/5381/wiki/8/WIKI20230321898323)

### 配置编译工具链

#### A7 编译：

-   a7 编译工具链：[cortexa7t2hf-neon-vfpv4-openstlinux_weston-linux-gnueabi.tar](https://onebox.huawei.com/p/c91f7e9eccbca77cfcc3454f4b647e4d)
-   stm 编译工具链：[x86_64-openstlinux_weston_sdk-linux.tar](https://onebox.huawei.com/p/f277e56a9f7d5897fe4ac1ab46bed26d)

```bash
# 解压
tar -xf cortexa7t2hf-neon-vfpv4-openstlinux_weston-linux-gnueabi.tar && tar -xf x86_64-openstlinux_weston_sdk-linux.tar
# 创建目录结构
sudo mkdir -vp /opt/st/SDK/sysroots
# 移到绝对路径 
sudo mv ./x86_64-openstlinux_weston_sdk-linux ./cortexa7t2hf-neon-vfpv4-openstlinux_weston-linux-gnueabi /opt/st/SDK/sysroots/
# 在 ~/.bashrc 添加环境变量
export PATH=$PATH:/opt/st/SDK/sysroots/x86_64-openstlinux_weston_sdk-linux/usr/bin/arm-openstlinux_weston-linux-gnueabi
export CORTEX_A7_SYSROOT=/opt/st/SDK/sysroots/cortexa7t2hf-neon-vfpv4-openstlinux_weston-linux-gnueabi
fi
source ~/.bashrc
# 验证环境变量配置成功
which arm-openstlinux_weston-linux-gnueabi-g++
# out: /opt/st/SDK/sysroots/x86_64-openstlinux_weston_sdk-linux/usr/bin/arm-openstlinux_weston-linux-gnueabi/arm-openstlinux_weston-linux-gnueabi-g++
```

#### RTOS_A7 编译：

```bash
# artget 下载到当前文件夹
artget pull "BiSheng Embedded CPU 301.0.0.B015" -ru software -user p_eMAPCI -pwd encryption:ETMsDgAAAYDW0EdtABRBRVMvQ0JDL1BLQ1M1UGFkZGluZwCAABAAEOydo0pZBnl0vMOup/a68ccAAAAgJCDhDHilmv81VoyM3snPz76C1flg+dPuAatwC+CUi/sAFJWlZ65BWIRNjtH95fJT48VNhmcT -rp "arm/hcc_arm32le/hcc_arm32le.tar.gz|arm/hcc_arm_eabi/hcc_arm_eabi.tar.gz" -ap "./"
# 解压
tar -xzf ./hcc_arm_eabi.tar.gz && tar -xzf ./hcc_arm32le.tar.gz
# 创建目录结构
sudo mkdir -vp /opt/buildtools/bisheng_embedded_cpu-301.0.0
# 移动到绝对路径
sudo mv ./hcc_arm_eabi ./hcc_arm32le /opt/buildtools/bisheng_embedded_cpu-301.0.0
# 在 ~/.bashrc 添加环境变量
export PATH=$PATH:/opt/buildtools/bisheng_embedded_cpu-301.0.0/hcc_arm_eabi/bin:/opt/buildtools/bisheng_embedded_cpu-301.0.0/hcc_arm32le/bin
source ~/.bashrc
# 验证环境变量配置成功
which arm-linux-gnueabi-g++
# out: /opt/buildtools/bisheng_embedded_cpu-301.0.0/hcc_arm32le/bin/arm-linux-gnueabi-g++
```

### 配置多架构支持的编译器

```bash
sudo apt-get install gcc-multilib g++-multilib
```

### CMake 升级

-   [cmake-3.27.0-rc4-linux-x86_64.tar.gz](https://github.com/Kitware/CMake/releases/download/v3.27.0-rc4/cmake-3.27.0-rc4-linux-x86_64.tar.gz)

```bash
# 下载
wget https://github.com/Kitware/CMake/releases/download/v3.27.0-rc4/cmake-3.27.0-rc4-linux-x86_64.tar.gz
# 解压
tar -xvzf cmake-3.27.0-rc4-linux-x86_64.tar.gz
sudo mv cmake-3.27.0-rc4-linux-x86_64 /opt/cmake-3.27.0
# 创建软链接
sudo ln -sf /opt/cmake-3.27.0/bin/* /usr/bin/
# 查看版本
cmake --version
```

### 将 Ubuntu 默认 sh 指向 bash

-   Ubuntu默认sh是指向dash而非bash，dash比bash更加轻量，甚至不支持函数功能，会导致编译问题

```bash
# 进入 root
sudo su
# 重新配置 dash
dpkg-reconfigure dash
# 选择 <No>/<否>
```

## 其他配置

### 配置编译缓存 `cache` 加速编译

-   `sudo apt-get install ccache`
-   然后在 `~/.bashrc` 添加环境变量

```bash
export CCACHE=1
export CCACHE_DIR=/path/to/home/dir/tmp/cache
export CC=ccache gcc
export CXX=ccache g++
```

-   结果：编译时内存占用减少 2/3，编译时间减少 1/2

-   查看和清除 `ccache`

```bash
# 查看
ccache -s
# 清除所有缓存
ccache -C
```

### 禁止 docker 启动

-   编辑 `~/.wsl_auto_setup/init.sh` 替换为以下移除启动docker的脚本

```bash
#!/bin/bash

function check_systemctl() {
    for service in $1; do
        sudo systemctl start "$service"
    done
}

function check_service() {
    for service in $1; do
        if [ "$(service "$service" status | grep "is not" | wc -l)" -eq 1 ]; then
            sudo service "$service" start
        fi
    done
}

system_init=$(ps --no-headers -o comm 1)
if [ "$system_init" == "systemd" ]; then
    if [ "$(lsb_release -d | grep Ubuntu | wc -l)" -ne 0 ]; then
        check_systemctl "cron sshd cntlm"
    else
        check_systemctl "crond sshd cntlm"
    fi
else
    check_service "cron ssh cntlm"
fi

# check vscode
if [ "$(ps -ef | grep vscode | wc -l)" -eq 1 ]; then
    vscode-server start
fi

if [ -d "/run/user/1001" ]; then
    sudo chown 1001:100 /run/user/1001
    sudo chmod 755 /run/user/1001
fi

# check Spes
if [ -z "$(pgrep SpesAuthService)" ]; then
    sudo /usr/local/spes/spesservice.sh start
    sudo /usr/local/spes/Composites/SpesClient/spesauthservice.sh start
fi
```

### 移除 docker

```bash
# 删除 docker 及安装时自动安装的所有包
sudo apt-get autoremove docker docker-ce docker-engine  docker.io  containerd runc
# 删除无用配置文件
dpkg -l |grep ^rc|awk '{print $2}' |sudo xargs dpkg -P
# 删除相关插件
sudo apt-get autoremove docker-ce-*
# 删除 docker 相关配置&目录
sudo rm -rf /etc/systemd/system/docker.service.d
sudo rm -rf /var/lib/docker
# 移除后执行 wsl --shutdown 再打开，dockerd 服务已关闭
```

### 配置 WSL2 允许密码登录

```bash
# 编辑 ssh 服务配置
sudo vim /etc/ssh/sshd_config.d/my_config.conf
# 添加到 my_config.conf
Port 2222
AddressFamily any
ListenAddress 0.0.0.0
ListenAddress ::
PasswordAuthentication yes
```

### 配置 windows 转发端口

-   目的是使外部 ssh 请求全部转发到 WSL2

```powershell
# 以下在 powershell/cmd 执行
netsh interface portproxy set v4tov4 listenport=22 listenaddress=0.0.0.0 connectport=2222 connectaddress=172.18.104.98
# listenport: 监听外部端口，22 为 ssh 默认端口
# listenaddress: 监听地址，0.0.0.0 指所有地址
# connectport: 转发到本地的端口，2222 为 WSL2 的 ssh 服务监听地址
# connectaddress: 转发到本地的地址，WSL2 的 ip 地址
```

-   此时单板可以通过 `scp` 命令拷贝本地的文件了

### 安装 lcov(开发测试用例覆盖率检测工具)

-   [lcov-1.15.tar.gz](https://github.com/linux-test-project/lcov/releases/download/v1.15/lcov-1.15.tar.gz)
-   使用旧版的原因：DTCenter使用新版 LCOV 会出现指令兼容性问题

```bash
# 下载
wget https://github.com/linux-test-project/lcov/releases/download/v1.15/lcov-1.15.tar.gz
# 解压
tar -xvzf lcov-1.15.tar.gz
# 安装
cd lcov-1.15
sudo make install
# 验证
lcov -v
```

![image-20230817221008556](http://image.huawei.com/tiny-lts/v1/images/0324e61b16bafcda4b400200c41b9589_1342x317.png)

### 限制 WSL 资源使用

-   WSL2 默认能够与 windows 交换50%运行内存，有时一不注意 Vmmem 就能吃掉16G内存
-   处理器可以选择16核或8核，其他选项会导致编译问题
-   编辑 Windows 用户目录下 `~/.wslconfig`

```yaml
[wsl2]
processors=8
memory=8GB
swap=8GB
localhostForwarding=true
```

### 升级 code-server

-   添加获取自动安装脚本并执行的命令到新文件 `~/vscode-server/update_code_server.sh`

```bash
sudo bash -c "$(curl -L -k -s -o- https://hicode-assets.tools.huawei.com/vscode-huawei/code-server/install.sh)"
```

-   为文件赋予 755 权限
-   后续升级可以直接执行该脚本

## 问题&解决

### 无法进入 root 用户 / 改密码

```bash
# 进入 root
sudo su
# 改密码
passwd root
```

### Perl 缺少 DateTime / JSON 模块

-   需要设置 cpan 代理来下载模块

```perl
# 进入 cpan 命令行
cpan
# 设置代理
o conf http_proxy http://proxy.huawei.com:8080
# 保存设置
o conf commit
# 退出 cpan 命令行
quit
# 下载模块
sudo cpan install DateTime JSON
```

<img src="http://image.huawei.com/tiny-lts/v1/images/5b57efa42ceadfdc147e098cd539dc35_975x744.png" alt="image-20230821120201051" style="zoom:80%;" />

### 我需要编译 ACC 代码，需要哪些配置

#### 添加编译工具链绝对路径到系统变量

-   在任一系统变量定义位置定义 `CORTEX_A7_SYSROOT` 也就是 [cortexa7t2hf-neon-vfpv4-openstlinux_weston-linux-gnueabi.tar](https://onebox.huawei.com/p/c91f7e9eccbca77cfcc3454f4b647e4d) 工具链的位置 `/opt/st/SDK/sysroots/cortexa7t2hf-neon-vfpv4-openstlinux_weston-linux-gnueabi`

```bash
# 以 ~/.bashrc 为例
export CORTEX_A7_SYSROOT=/opt/st/SDK/sysroots/cortexa7t2hf-neon-vfpv4-openstlinux_weston-linux-gnueabi
```

-   添加完毕保存后执行 `source ~/.bashrc` 即可

#### 安装开源字体工具 `fonttools`

-   `sudo apt install fonttools`

### 自定义 WSL 自动拉起脚本

-   `vim ~/.wsl-auto-setup/init.sh`
