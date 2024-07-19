## 关闭VSCode侧边栏文件错误颜色

`"problems.decorations.enabled": false`

## 为vscode-huawei和vscode分别指定插件位置

- 分别更改vscode和wecode的`属性-快捷方式-目标`为

```bash
code.exe --extension-dir "<User Profile>/.vscode/extensions"
vscode-huawei.exe --extension-dir "<User Profile>/.wecode/extensions"
```

- 为右键打开文件指定插件位置
  - 依次点开 `HKEY_CLASSES_ROOT/*/shell/VSCode/command`，假如没有后面两个文件夹需要新增
  - 没有右键菜单选项的需要添加，右键 shell ，新建 —> 项，给创建的文件夹命名为 VSCode
  - 默认的数值修改为 用VSCode打开
  - 再右键VSCode，新建 —> 可扩充字符串值，名称为 Icon，数值修改为 VSCode 的 exe 文件路径
  - 再右键VSCode，新建 —> 项，给创建的文件夹命名为 command，修改 command 的数值，即前面的快捷方式目标参数，按照个人配置来
    `"D:\工具\Microsoft VS Code\Code.exe" --extensions-dir  "D:\工具\Microsoft VS Code\extensions" "%1"`


- 配置右键打开文件夹
  
  - 依次点开 `HKEY_CLASSES_ROOT/ Directory/shell`，操作与上同，修改 command 的数值
  
  
  - `"D:\工具\Microsoft VS Code\Code.exe" --extensions-dir  "D:\工具\Microsoft VS Code\extensions" "%V"`
  
- 配置右键文件夹空白处，打开文件夹


  - 依次点开 `HKEY_CLASSES_ROOT/Directory/Background/shell`，操作与上同，修改 command 的数值
  - `"D:\工具\Microsoft VS Code\Code.exe" --extensions-dir  "D:\工具\Microsoft VS Code\extensions" "%V"`

## VSCode显示大括号配对和括号范围高亮

```json
{
	"editor.renderWhitespace": "all",  // 渲染空格
    "editor.bracketPairColorization.independentColorPoolPerBracketType": true,  // 每种括号对有自己的颜色池
    "editor.guides.bracketPairs": "active",  // 显示大括号范围
}
```

## VSCode文件类型按照.cpp和.h配对

<img src="http://image.huawei.com/tiny-lts/v1/images/3ea8563ae912de5ffe4a62f389a949eb_288x523.png" alt="image-20230728110154171" style="zoom: 67%;" />

```json
{
    "explorer.sortOrder": "default", // 控制资源管理器中的文件和文件夹基于属性进行排序
}
```

## VSCode文件.cpp中嵌套.h

<img src="http://image.huawei.com/tiny-lts/v1/images/f547efb64092bcbf8a7f3216da1921ed_324x521.png" alt="image-20230728110221078" style="zoom: 67%;" />

```json
{
    "explorer.fileNesting.enabled": true,
    "explorer.fileNesting.patterns": {
        "*.cpp": "${capture}.cpp, ${capture}.h"
    },
}
```

## Gitlens取消每个函数前的作者等信息

```json
{
	"gitlens.codeLens.enabled": false,
}
```

## VSCode 个性化配置

```bash
{
	"workbench.colorCustomizations": {
        // 终端选中文本背景色
        "terminal.selectionBackground": "#363636",
        // 侧边栏子标题栏背景色
        "sideBarSectionHeader.background": "#315db3",
    },
}
```

## `F8` 高亮设置

-   这是 `WeCodeTeam.wecodefoundation` 插件提供的功能

## 快捷产生 GDB 断点命令

-   这是 `VSCode-huawei.gen-gdb-cmd` 插件提供的功能，可以设置快捷键快速生成命令存入剪贴板，如：

```json
// keybindings.json
[
    {
        "key": "alt+b",
        "command": "gengdbcmd.genBreakPointCmd"
    },
]
```

## VSCode 为 Huawei C/C++ 添加额外的 Clangd 参数

```json
{
    "wecode-cpp.codebase.arguments.additional": [
        "-Wno-dangling-else",
        "-Wno-inconsistent-missing-override",
        "-DVOS_CPU_TYPE=VOS_9200",
        "-DVOS_OS_VER=VOS_LINUX",
        "-DVOS_HARDWARE_PLATFORM=VOS_ARM",
        "-DVOS_BYTE_ORDER=VOS_LITTLE_ENDIAN",
        "-DEMAP_CPU_ENDIAN=EMAP_ENDIAN_LITTLE",
        "-DEMAP_OS_TYPE=EMAP_OS_LINUX",
    ],
}
```

## VSCode 打开文件时自动识别并切换编码

```json
{    
	"files.autoGuessEncoding": true,
}
```

## VSCode 当前工位配置

```json
// settings.json
{
    "workbench.sideBar.location": "right",
    "workbench.startupEditor": "none",
    "workbench.list.smoothScrolling": true,
    "workbench.iconTheme": "catppuccin-macchiato",
    "workbench.editor.wrapTabs": true,
    "workbench.editor.empty.hint": "hidden",

    "window.commandCenter": true,
    "window.title": "${rootName}${separator}${dirty}${separator}${profileName}${separator}${appName}",

    "editor.fontFamily": "Maple Mono NF CN, SF Mono SC, 'PingFang SC', monospace",
    "editor.fontSize": 16,
    "editor.inlayHints.fontFamily": "Maple Mono NF CN, SF Mono SC",
    "editor.suggestFontSize": 14,
    "editor.codeLensFontFamily": "Maple Mono NF CN, SF Mono SC",
    "editor.cursorBlinking": "phase",
    "editor.guides.bracketPairsHorizontal": "active",
    "editor.renderWhitespace": "all",
    "editor.guides.bracketPairs": true,
    "editor.cursorStyle": "block",
    "editor.lineHeight": 2,
    "editor.smoothScrolling": true,
    "editor.stickyScroll.enabled": true,
    "editor.mouseWheelZoom": true,
    "editor.rulers": [
        120,
        150,
    ],
    "editor.accessibilitySupport": "off",
    "editor.cursorSmoothCaretAnimation": "on",
    "editor.editContextMenu": [
        "Open Changes",
        "Copy as",
        "Git: View File History",
        "Git: View Line History",
    ],
    "editor.scrollbar.horizontal": "visible",
    "editor.scrollbar.verticalScrollbarSize": 10,
    "editor.scrollbar.vertical": "visible",
    "editor.scrollbar.horizontalScrollbarSize": 10,
    "editor.bracketPairColorization.independentColorPoolPerBracketType": true,
    "editor.wordWrap": "off",
    "editor.guides.indentation": false,
    "editor.fontLigatures": true,
    "editor.fontWeight": "300",

    "markdown.preview.lineHeight": 3,
    "markdown.preview.fontFamily": "Maple Mono NF CN, -apple-system, BlinkMacSystemFont, 'Segoe WPC', 'Segoe UI', system-ui, 'Ubuntu', 'Droid Sans', sans-serif",

    "terminal.integrated.fontSize": 16,
    "terminal.integrated.fontFamily": "Maple Mono NF CN, SF Mono SC, PingFang SC",
    "terminal.integrated.smoothScrolling": true,
    "terminal.integrated.enableMultiLinePasteWarning": "never",
    "terminal.integrated.lineHeight": 1.6,
    "terminal.integrated.tabs.defaultColor": "terminal.ansiCyan",

    "debug.console.fontFamily": "Maple Mono NF CN, SF Mono SC, PingFang SC",
    "debug.console.lineHeight": 30,

    "files.trimFinalNewlines": true,
    "files.trimTrailingWhitespace": true,
    "files.autoGuessEncoding": true,

    "explorer.confirmDelete": false,
    "explorer.fileNesting.enabled": true,
    "explorer.fileNesting.patterns": {
        "*.cpp": "${capture}.cpp, ${capture}.h"
    },
    "explorer.confirmDragAndDrop": false,

    "[python]": {
        "editor.formatOnType": true
    },
    "python.languageServer": "Pylance",

    "extensions.ignoreRecommendations": true,

    "remote.SSH.remotePlatform": {
        "7.225.48.28": "linux",
        "7.189.108.78": "linux"
    },

    "git.autofetch": true,

    "cmake.configureOnOpen": false,

    "cmake.options.statusBarVisibility": "visible",
    "cmake.showOptionsMovedNotification": false,
    "git.showCommitInput": false,
    "git.repositoryScanMaxDepth": -1,
    "git.closeDiffOnOperation": true,
    "remote.localPortHost": "allInterfaces",
    "wecode-cpp.reference.isAppendMode": false,
    "editor.suggest.selectionMode": "whenQuickSuggestion",
    "editor.quickSuggestionsDelay": 0,
    "gitlens.graph.dateStyle": "absolute",
    "gitlens.defaultDateStyle": "absolute",
    "remote.SSH.externalSSH_ASKPASS": true,
    "terminal.integrated.defaultProfile.windows": "Git Bash",
    "git-graph.integratedTerminalShell": "E:\\Program Files\\Git\\bin\\bash.exe",
    "gitlens.codeLens.enabled": false,
    "window.zoomLevel": -1,

    // "highlightwords.colors": [
    //     { "light": "#b3d9ff", "dark": "cyan" },
    //     { "light": "#e6ffb3", "dark": "pink" },
    //     { "light": "#b3b3ff", "dark": "lightgreen" },
    //     { "light": "#ffd9b3", "dark": "magenta" },
    //     { "light": "#ffb3ff", "dark": "cornflowerblue" },
    //     { "light": "#b3ffb3", "dark": "orange" },
    //     { "light": "#ffff80", "dark": "green" },
    //     { "light": "#d1e0e0", "dark": "red" },
    // ],

    "highlightwords.colors": [
        { "light": "#ff0000", "dark": "#d7bd02" },
        { "light": "#00ffff", "dark": "#14892e" },
        { "light": "#ff7f00", "dark": "#82e0aa" },
        { "light": "#00ff00", "dark": "#f9e79f" },
        { "light": "#00fa9a", "dark": "#d0392b" },
        { "light": "#00ff00", "dark": "#94c5bb" }
    ],
    "highlightwords.box": {
        "light": false,
        "dark": false
    },
    "highlightwords.defaultMode": {
        "default": 0
    },
    "highlightwords.showSidebar": {
        "default": true
    },

    "workbench.layoutControl.enabled": false,
    "workbench.activityBar.location": "bottom",
    "workbench.tree.indent": 20,

    "zenMode.hideStatusBar": false,

    "editor.inlayHints.enabled": "off",
    "workbench.colorCustomizations": {
        // "editor.lineHighlightBackground": "#1073cf2d",
        // "editor.lineHighlightBorder": "#9fced11f",
        "terminal.findMatchBackground": "#2c8a00d7",
        "terminal.selectionForeground": "#ff5e00",
    },
    "diffEditor.wordWrap": "off",
    "security.workspace.trust.untrustedFiles": "open",

    "background.enabled": true,
    "background.fullscreen": {
        "images": ["file:///C://Users//h30045134//Pictures//flowers.png"], // urls of your images
        "opacity": 0.90, // 0.85 ~ 0.95 recommended
        "size": "cover", // also css, `cover` to self-adaption (recommended)，or `contain`、`200px 200px`
        "position": "center", // alias to `background-position`, default `center`
        "interval": 0, // seconds of interval for carousel, default `0` to disabled.
    },
    "background.style": {
        "filter": "blur(10px)",
    },

    "remote.SSH.useExecServer": false,

    "terminal.integrated.tabs.enabled": false,
    "terminal.integrated.gpuAcceleration": "on",

    "apc.activityBar": {
        "position": "bottom", // top: above sidebar, bottom: below sidebar (default: 'left' if unspecified)
        "size": 40, // Height (when top/bottom) or width (in default position)
        "itemSize": 30, // Size of items within the bar (default: size)
        "itemMargin": 3 // Margin between two items (default: 3)
    },
    "apc.statusBar": {
        "position": "editor-bottom",
        "height": 35,
        "fontSize": 14,
    },
    "apc.electron": {
        "frame": false,
        "backgroundColor": "rgba(0,0,0,0.95)",
        "vibrancy": "ultra-dark",
        "visualEffectState": "active",
    },
    "apc.font.family": "Maple Mono",
    "window.titleBarStyle": "native",
    "breadcrumbs.enabled": true,
    "editor.minimap.enabled": true,

    "window.menuBarVisibility": "compact",
    "update.mode": "manual",
    "WeCode.InstallPath": "d:\\WeCode",
    "WeCode.GitPath": "E:\\Program Files\\Git\\cmd\\git.exe",
    "files.associations": {
        "*.toml": "toml"
    },

    "clangd.path": "c:\\Users\\h30045134\\AppData\\Roaming\\Code\\User\\globalStorage\\llvm-vs-code-extensions.vscode-clangd\\install\\18.1.3\\clangd_18.1.3\\bin\\clangd.exe",
    "clangd.fallbackFlags": [
        "-IE:\\DevEnv\\mingw64\\include",
        "-IE:\\DevEnv\\mingw64\\x86_64-w64-mingw32\\include",
        "-IE:\\DevEnv\\mingw64\\lib\\gcc\\x86_64-w64-mingw32\\8.1.0",
        "-IE:\\DevEnv\\mingw64\\lib\\gcc\\x86_64-w64-mingw32\\8.1.0\\include",
        "-IE:\\DevEnv\\mingw64\\lib\\gcc\\x86_64-w64-mingw32\\8.1.0\\include\\c++",
        "-IE:\\DevEnv\\mingw64\\lib\\gcc\\x86_64-w64-mingw32\\8.1.0\\include\\c++\\x86_64-w64-mingw32",
        "--target=x86_64-w64-windows-gnu",
    ],

    "WeCode.changeOpenShowNews": false,
    "cmake.pinnedCommands": [
        "workbench.action.tasks.configureTaskRunner",
        "workbench.action.tasks.runTask"
    ],
    "clangd.inactiveRegions.useBackgroundHighlight": true,
    "C_Cpp.intelliSenseEngine": "Disabled",
    "C_Cpp.autocomplete": "Disabled",
    "codecheck.CodeCheckOffline": true,
    "markdown-preview-enhanced.codeBlockTheme": "vue.css",
    "markdown-preview-enhanced.previewTheme": "vue.css",
    "markdown-preview-enhanced.revealjsTheme": "blood.css",
    "workspaceKeybindings.wecode.createDefinitionInSourceFile.enabled": true,
    "workspaceKeybindings.cmantic.createDefinitionInSourceFile.enabled": false,
    "C_mantic.cpp.curlyBraceFormat.function": "New line",
    "editor.largeFileOptimizations": false,
    "workbench.colorTheme": "Catppuccin Alt Mocha",
}
```

