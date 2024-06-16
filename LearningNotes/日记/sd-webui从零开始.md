## 配置 `python` 环境，安装 `venv`

以 `miniconda` 为例

```bash
# 因为直接使用venv，所已不需要在conda管理的环境中直接安装依赖
## 直接创建对应版本的环境即可
conda create -n normal python=3.10.6 # 需要指定为sd-webui官方要求的版本

# 安装venv，便于后续一键完成全部安装
conda activate normal
pip install -U venv

# 克隆stable-diffusion-webui
git clone https://github.com/AUTOMATIC1111/stable-diffusion-webui.git sd-webui

# 安装tb-nightly，因为清华镜像存在找不到tb-nightly的情况，所以使用阿里云镜像替代
$SD_WEBUI_ROOT/venv/Scripts/python.exe -m pip install tb-nightly -i https://mirrors.aliyun.com/pypi/simple

# 设置COMMANDLINE_ARGS
# file: webui-user.bat
set COMMANDLINE_ARGS=--enable-insecure-extension-access --opt-sdp-no-mem-attention --xformers --pin-shared-memory --cuda-malloc --cuda-stream

# 打开ACCELERATE="true"
# file: webui-user.bat
set ACCELERATE="true"

# 注释accelerate配置文件default_config.yaml中的debug选项
# file: %USERPROFILE%\.cache\huggingface\accelerate\default_config.yaml

# 运行一键安装启动脚本
./webui-user.bat
```



