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

