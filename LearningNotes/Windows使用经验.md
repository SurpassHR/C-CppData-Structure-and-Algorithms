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


#### 5.最终方法，在不开启Reigion->System Locale->Beta Unicode UTF-8选项的前提下使 `git log`、`git status`、`ls` 正常显示

1. `git config --global core.quotePath false` 解决 `git status` 显示 `new file:   "../\345\223\210\345\223\210.txt"` 的问题
2. 修改终端 `locale` 和 `charset` : 为 `zh_CN` 和 `UTF-8`，实际上只与 `charset` 相关
3. 对于某些不能直接通过选项设置 `locale` 和 `charset` 的，需要手动 `export LC_ALL=zh_CN.UTF-8` 或者 `export LANG=zh_CN.UTF-8`，之后可以添加到 `~/.bashrc` 中，`bash` 可能不能很好的支持 `/etc/profile` 中的内容
4. gitk乱码修复 `git config --global gui.encoding utf-8`
5.   `git log` 显示 `<B2><BB><D0>޸ĵ<D8><C7><F8>Unicode UTF-8ѡ<CF><EE><B5><C4>ǰ<CC><E1><CF>½<E2><BE><F6>bash<C2><D2><C2><EB><CE><CA><CC><E2>` 则修改 `git config --global i18n.logOutputEncoding utf-8`
6. 修改注册表字符编码页 `HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage`
   - 其中，ACP和OEMCP分别定义了Windows系统在图形用户界面和命令行界面中使用的字符编码；
   - 解决 `git` 中的全部问题只需要修改 `OEMCP` 值为 `65001`

### 解决每次注销或重启后远程服务器网络凭据过期

- 打开凭据管理器，添加Windows凭据

![image-20240524094357966](http://image.huawei.com/tiny-lts/v1/images/46899f8554c4f08eaf699cde6bfa6d60_493x166.png)
