## git 基本问题

### git 格式化提交信息

-   在任意位置（以家目录 `~` 进行演示）创建提交信息模板文件 `.git_commit_template`

```bash
Description:
Design Doc:
Change Type(新增需求/缺陷修改): 新增需求
Change Code(主控/显示/协议): 主控
Affected Products(eSTORE): eSTORE
Affected Fields(NA/网管/ECC/资料/装备): NA
Affected History Product(Y/N): N
Transfer to Test(Y/N): N
Tester:
Test Suggestion:
Self-test Report:
```

-   编辑 `~/.gitconfig`，添加

```bash
[commit]
	template = ~/.git_commit_template
```

-   提交时使用 `git commit` 会打开一个可交互的编辑器页面来编辑提交信息

## git-mm 相关问题

### git-mm凭证初始化

```bash
#! /bin/bash
# 在 git bash 中执行
set USER_NAME=<域账户用户名>
set USER_PASSWD=<域账户密码>

git credential-manager remove
git mm credential install
git mm credential --store -u='${USER_NAME}' -p='${USER_PASSWD}' --host "*"
```

按照上述流程完成后，查看 `~/.git-mm-credential` 内容应当如下

```bash
[{"Protocol":"https","Host":"*","Path":"*","Username":"h30045134","Password":"QWElMjEwOTQxNjE3NTM="}]
```

### 解决每年更换域账号密码后 `git-mm credential` 失效，导致 `git-mm` 同步多仓时弹出 windows 凭证窗口

```bash
cat ~/.git-credential # 可以发现，git凭证管理中依然是旧密码
rm -rf ~/.git-credential
cd /path/to/your/code/root
rm -rf ./* ./.mm
git mm init ...
git mm sync
```

### git-mm指令和使用场景，`git-mm` 基于多仓项目的多分支管理

```bash
# 本地初始化远程分支 master
git mm init -u https://codehub-dg-y.huawei.com/Energy_Manifest/PublicProduct/LCC/LCC_Manifest.git -b master -m LCC/dependency.xml -g lcc,llt

# 本地初始化远程分支 br_LCC_V300R024C00_TR5-1_Release
git mm init -u https://codehub-dg-y.huawei.com/Energy_Manifest/PublicProduct/LCC/LCC_Manifest.git -b br_LCC_V300R024C00_TR5-1_Release -m LCC/dependency.xml -g lcc,llt

# 本地新建分支：
git mm start <分支名> --all

# 本地更新库上代码：
git mm sync

# 本地拉取特定super-MR（如MR编号为66时）：
git mm cherry-pick -s 66

# 本地拉取特定MR后回退N个提交：
git reset --soft HEAD~N

# 本地查看改动点（在总仓路径下）：
git mm status

# 提交代码变更到本地（在子仓路径下）：
git add .（.表示提交当前目录下所有文件，也可以填写具体的文件名）

# 提交代码，asd为MR描述：
git commit -m "asd"

# 提交代码到上一次提交（在子仓路径下）：
git commit --amend

# 上传本地提交到仓库（在任意项目路径下）：
git mm upload

# 之后可选择具体的MR选择上传（Yes/No/Edit），Edit/e选项会打开一个可交互的编辑器界面(vim/nano)，取消注释commit的hash和提交内容即可提交

# 对所有子仓执行操作
git mm forall -- "<command>"
## 拓展举例: 删除所有子仓的某一分支
git mm forall -- "git branch -D <br_name>"
```

## git LFS指令和使用场景

```bash
# 安装 git-lfs（换源后的WSL或公司外）
sudo apt-get update && sudp apt-get install git-lfs

# 安装 git-lfs（公司内）
curl -k https://isource-pages.huawei.com/iSource/git-lfs/git_lfs_autoinstall.sh -o git_lfs_autoinstall.sh && sh git_lfs_autoinstall.sh

# 初始化新 git 本地仓库
git init
## ssh 传输的仓库协议，使用时记得上传本机 ssh 公钥
git remote add origin <远程仓库地址>
## 同步线上仓库文件到本地
### 同步前本地需要至少有一个分支
git pull

# 在本仓库使用 git-lfs
git lfs install

# 使用 lfs track / untrack 本地大文件
git lfs track <*file_name>
## 添加特殊文件规则到 .gitattribute
### 如将所有 .png 和 .jpg 使用 LFS 管理
### *.jpg filter=lfs diff=lfs merge=lfs -text
### *.png filter=lfs diff=lfs merge=lfs -text
git add .gitattribute

# 如果 git 运营商已经线上初始化过仓库则只需使用 git clone <git-url> 代替上述过程
git add <*file_name>
git commit -m "<commit message>"
GIT_TRACE=1 git push
```

## EMAP 代码下载及相关问题

### 申请EMAP相关子仓权限

找 **杨宸 005854108** 申请 `CMS` 和 `KMC` 仓权限，按照申请指导填写表格: [KMC一指禅](http://3ms.huawei.com/hi/group/3862259/wiki_6662430.html)

### 下载EMAP代码

```bash
# 初始化 EMAP 多仓目录
git mm init -u https://codehub-dg-y.huawei.com/Energy_Manifest/Platform/Platform_Component_Manifest.git -b master -m dependency.xml -g emap,emap_ai,emap_undefine,emap_test,emap_tools,emap_open_source

# 多线程同步多仓
git mm sync --force-sync -d --depth=1 -j32
```