-   打开卓越性能模式 `powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61`

-   Windows 商店离线软件包 [rg-adguard.net](https://store.rg-adguard.net/)

-   `git-bash / bash` 乱码解决

    -   终端不能显示中文：打开 Git bash，右键打开选项， `Options->Text->Locale` 改为 `zh_CN`，`Character set` 改为 `UTF-8`

    -   解决 git status 不能显示中文：终端输入 `git config --global core.quotepath false`

-   终端登录 `git-bash / bash` 时需要添加 `--login -i` 参数

-   右键菜单在目录背景下打开 `git-bash / bash`
    -   `"E:\Program Files\Git\bin\bash.exe" -c "cd '%V' && exec /bin/bash"`
-   右键菜单单击目录打开 `git-bash / bash`
    -   `"E:\Program Files\Git\bin\bash.exe" -c "cd '%1' && exec /bin/bash"`

### Windows 乱码解决

#### 在Windows的CMD中如何设置支持UTF8编码?

1.  输入 CHCP，回车查看当前的编码 936表示当前使用的是简体中文（GB2312）编码；

2.  输入CHCP 65001，回车；

3.  属性设置字体为 Lucida Console 支持UTF8的正常显示；

4.  在CMD增加更多的字体；
    注册表（路径：HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Console\TrueTypeFont）中添加就好了。需要注意的是，添加的字体需要是等宽的(fixed-width)。

    

#### 让Msys2 MinGW 的ls 支持中文utf-8编码

通过设置locale环境变量

终端乱码
1.判断环境
xshell -> 终端 -> ubuntu

所以乱码问题则出现在 xshell 与终端 编码配置不一致上。

1.  查看编码
    首先查看 xshell 编码：

    

Properties -> Terminal -> Encoding -> Unicode(UTF-8)
xshell编码 UTF-8

在终端执行 locale 查看编码：

LC_ALL="zh_CN.GBK"
终端编码 GBK

3.修改环境变量
把 export LC_ALL=zh_CN.UTF-8 写入文件/etc/profile
执行 source /etc/profile

注意： 如果执行source /etc/profile出现如下错误：

/bin/bash: warning: setlocale: LC_ALL: cannot change locale (zh_CN.UTF-8)
先安装zh_CN.UTF-8，执行locale-gen zh_CN.UTF-8 ,再使用locale查看是否已修改

修改环境变量有三种方式 ：

export ： 暂时性，重新登录就失效

写入 ~/.bashrc : 长久性，只对当前用户生效

写入 /etc/profile ；长久性，对所有用户生效

bash（终端）的环境变量读入顺序 /etc/profile -> ~/.bashrc -> export (后者会覆盖前者设置)

注意：后两种修改方式需要重新登录或者执行 sourcr ~/.bashrc（/etc/profile）才可生效

### vim乱码

1.  连接方式
    xshell -> Terminal -> vim
2.  修改配置文件
    需要vim的编码方式与Terminal(终端)统一，在vim的配置文件~/.vimrc 写入：

set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936 # 读入的文件编码，因为无法确定文件编码，所以要全写上

```
let &termencoding=&encoding
set termencoding=utf-8      # 在终端显示时的编码，需与终端一致
set encoding=utf-8          # vim本身的编码，默认为utf-8 这个最重要
```

修改.vimrc 有两种方式(文件不存在就创建一个新的)

~/.vimrc : 长久性，当前用户生效
/etc/vim/vimrc : 长久性，所有用户生效

#### Git 乱码

查看git log时乱码
在 Startup -> Environment 中添加下面的语句：
`set LANG=zh_CN.UTF-8`
配置git log的输出
`git config --global i18n.logoutputencoding utf-8`

Git 是在linux下开发的，而 Linux 的编码方式是基于 UTF-8 的，所以移植到 Windows 之后难免会存在编码冲突，导致乱码。Git 在 Windows 下有多种乱码情况，请按具体情况操作～
假设 Git 安装目录为 C:\Git

1.使用 git add 命令添加文件名含中文字符的文件时
1.1 乱码类似：

```
\316\304\261\276\316\304\265\265.txt
```

1.2 解决方案：
编辑 C:\Git\etc\inputrc 文件中对应的行，查找以下2行，并修改其值，
原先：

```
set output-meta off
set convert-meta on
```

改为：

```
set output-meta on
set convert-meta off
```

2.使用git log查看含有中文的log信息时
2.1 乱码类似：

```
<E4><BF><AE><E6><94><B9><E6><96><87><E6><9C><AC><E6><96><87><E6><A1><A3>
```

2.2 解决方案：
在Bash提示符下输入：

```
git config --global i18n.commitencoding utf-8
git config --global i18n.logoutputencoding gbk
```

注：设置 commit 提交时使用 utf-8 编码，可避免 Linux 服务器上乱码；同时设置在执行 git log 时将 utf-8 编码转换成 gbk 编码，以解决乱码问题。
编辑 C:\Git\etc\profile 文件，添加如下一行：

```
export LESSCHARSET=utf-8
```

注：以使git log可以正常显示中文（需要配合：i18n.logoutputencoding gbk）

#### 3.使用ls命令查看含有中文的文件名乱码时

3.1 乱码类似：

```
????.txt
???????.md
```

3.2 解决方案：
使用 ls --show-control-chars 命令来强制使用控制台字符编码显示文件名，即可查看中文文件名。
为了方便使用，可以编辑 C:Gitetcgit-completion.bash 文件，添加如下一行：

```
alias ls="ls --show-control-chars"
```

#### 4.在Git Gui中查看UTF-8编码的文本文件时

4.1 乱码类似：

```
锘夸腑鏂囨枃妗￡
```

4.2 解决方案：
在Bash提示符下输入：

```
git config --global gui.encoding utf-8
```

注：通过上述设置，UTF-8 编码的文本文件可以正常查看，但是 GBK 编码的文件将会乱码，所以还是没有从根本上解决问题。

可行的方法之一为：将所有文本文件的编码统一为 UTF-8 或 GBK，然后设置相应的gui.encoding 参数为 utf-8 或 gbk
