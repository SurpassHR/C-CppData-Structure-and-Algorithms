## git mm凭证初始化

```bash
#! /bin/bash
# 在 git bash 中执行
set USER_NAME=h30045134
set USER_PASSWD=Aa!094161753

git credential-manager remove
git mm credential install
git mm credential --store -u='${USER_NAME}' -p='${USER_PASSWD}'
```

按照上述流程完成后，查看 `~/.git-mm-credential` 内容应当如下

```bash
[{"Protocol":"https","Host":"*","Path":"*","Username":"h30045134","Password":"QWElMjEwOTQxNjE3NTM="}]
```

## 申请EMAP相关子仓权限

找 **杨宸 005854108** 申请 `CMS` 和 `KMC` 仓权限，按照申请指导填写表格: [KMC一指禅](http://3ms.huawei.com/hi/group/3862259/wiki_6662430.html)

## 下载EMAP代码

```bash
# 安装升级 git lfs
curl -k https://isource-pages.huawei.com/iSource/git-lfs/git_lfs_autoinstall.sh -o git_lfs_autoinstall.sh && sh git_lfs_autoinstall.sh

# 初始化 EMAP 多仓目录
git mm init -u https://codehub-dg-y.huawei.com/Energy_Manifest/Platform/Platform_Component_Manifest.git -b master -m dependency.xml -g emap,emap_ai,emap_undefine,emap_test,emap_tools

# 多线程同步多仓
git mm sync --force-sync -d --depth=1 -j32
```
