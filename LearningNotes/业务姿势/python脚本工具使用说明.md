## 先看问题

### Q: 双击 `.py` 脚本后弹出黑框闪退怎么办

-   A: 此时应该在脚本目录下 `shift + 鼠标右键`，选择 `在powershell` 中打开，然后 `python [脚本名.py]`，就可以看到是什么错误导致的闪退，一般有几种原因：
    -   1.   缺少依赖，可以看到命令行最后提示 `no module named 'xxx'`，此时直接 `pip install xxx`，若找不到包则是因为包名与导入时的模块名不同，此时直接百度 `python 安装 xxx`
    -	2.   其他的脚本正在运行，有的模块不能多开，如 `tftp`，提示字样有 `xxx socket`、`套接字`等?

## python环境搭建(只需要看这个)

### 一键安装依赖

测试部给出的依赖版本文件 [requirements.txt](https://codehub-y.huawei.com/api/codehub/v1/projects/3064516/repository/blobs/75f20f27fd3b8ba1d48d07f764b8b63e848f405a/raw?file_name=requirements.txt)

```bash
# 安装列出依赖
pip install -r requirements.txt -i http://mirrors.tools.huawei.com/pypi/simple/ --trusted-host=mirrors.tools.huawei.com
## 存在多个python版本环境的使用对应版本下的pip，如:
python38 -m pip install -r requirements.txt -i http://mirrors.tools.huawei.com/pypi/simple/ --trusted-host=mirrors.tools.huawei.com
```

### 替换依赖中ftp库文件

测试部给出的替换文件 [handlers.py](https://codehub-y.huawei.com/api/codehub/v1/projects/3064516/repository/blobs/cb190120923d8f95cac4520c2965c7cd12b2735f/raw?file_name=handlers.py)

替换python安装目录下 `pyftpdlib` 库中的 `handlers.py` 文件

路径: `X:\path\to\python\root\Lib\site-packages\pyftpdlib\handlers.py`

> **注意：安装相应依赖后不要使用打包过的软件**

## BIN工具打包

## 修改相对路径（`pyinstaller` 无法解析相对路径）

```python
# ftps.py: 49左右
        if hasattr(sys, 'frozen'):
            cur_path = '../'
        else:
            cur_path = os.path.dirname(__file__)
```

替换为

```python
		cur_path = getattr(sys, '_MEIPASS', os.path.dirname(os.path.abspath(__file__)))
```

### 安装/升级 `pyinstaller`

`python -m pip install -U pyinstaller`

### 打包

`pyinstaller.exe LCC工具.py -F -p lib --clean`