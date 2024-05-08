## Git LFS(Large File Storage)

```bash
# 以 huggingface 为例，先安装 huggingface_cli，以下操作均在 linux-debian ubuntu distro 环境下进行
python -m pip install --upgrade pip && python -m pip install huggingface_hub

#安装 git-lfs
sudo apt-get update && sudp apt-get install git-lfs

# 初始化新 git 本地仓库
git init
## ssh 传输的仓库协议，使用时记得上传本机 ssh 公钥
git remote add origin git@hf.co:<Username>/<Repo Name> # 或 git remote add origin https://huggingface.co/<Username>/<Repo Name>
## 同步线上仓库文件到本地
### 同步前本地 branch 需要有一个
git pull

# 在本仓库使用 git-lfs
huggingface_cli lfs-enable-largefiles .
git lfs install

# 使用 lfs track / untrack 本地大文件
git lfs track <*file_name>
## 添加特殊文件规则到 .gitattribute，可以参考 https://huggingface.co/Model/SurpassHR/ModelBackup 中的写法
git add .gitattribute

# 如果 git 运营商已经线上初始化过仓库则只需使用 git clone <git-url> 代替上述过程
git add <*file_name>
git commit -m "<commit message>"
GIT_TRACE=1 git push
```