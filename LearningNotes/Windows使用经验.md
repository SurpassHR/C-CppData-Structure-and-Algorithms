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
