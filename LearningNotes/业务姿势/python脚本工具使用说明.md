## 安装对应依赖

测试部给出的依赖版本文件 [requirements.txt](https://codehub-y.huawei.com/api/codehub/v1/projects/3064516/repository/blobs/fe0aa87aa3fd4a5ae2a47693407cd204a30bb2a9/raw?file_name=requirements.txt)

```bash
# 安装列出依赖
pip install -r requirements.txt -i http://mirrors.tools.huawei.com/pypi/simple/ --trusted-host=mirrors.tools.huawei.com
## 存在多个python版本环境的使用对应版本下的pip，如:
python38 -m pip install -r requirements.txt -i http://mirrors.tools.huawei.com/pypi/simple/ --trusted-host=mirrors.tools.huawei.com
```

## 替换依赖中ftp库文件

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