## Git MM (Multi-Module)

```bash
# 本地克隆一份仓库代码：
git mm init -u https://codehub-dg-y.huawei.com/Energy_Manifest/PublicProduct/LCC/LCC_Manifest.git -b master -m LCC/dependency.xml -g lcc,llt

git mm init -u https://codehub-dg-y.huawei.com/Energy_Manifest/PublicProduct/LCC/LCC_Manifest.git -b br_LCC_V300R024C00_TR5-1_Release -m LCC/dependency.xml -g lcc,llt

git mm init -u https://codehub-dg-y.huawei.com/Energy_Manifest/PublicProduct/LCC/LCC_Manifest.git -b br_LCC_V300R024C10_TR5-1_Release -m LCC/dependency.xml -g lcc,llt

# 本地新建分支：
git mm start <分支名> --all

# 本地更新库上代码：
git mm sync

# 本地拉取特定MR（如MR编号为66时）：
git mm cherry-pick -s 66

# 本地拉取特定MR后回退一个提交：
git reset --soft HEAD~1

# 回退到指定时间时间
git mm reset --until "2024-04-07 17:00:00"

# 内容同步至目标分支
git mm forall -- 'git update-ref refs/heads/sys_debug HEAD'

# 本地查看改动点（在总仓路径下）：
git mm status

# 提交代码变更到本地（在子仓路径下）：
git add .（.表示提交当前目录下所有文件，也可以填写具体的文件名）

# 提交代码，asd为MR描述：
git commit -m "asd"

# 提交代码到上一次提交（在子仓路径下）：
git commit --amend

# 上传本地提交到仓库（在总仓路径下）：
git mm upload

# 之后可选择具体的MR选择上传（Yes/No/Edit）
```

## Some single repo git usage

```bash
# 等价替换
git pull == git fetch && git merge <remote_name>/<branch_name>
git pull --rebase == git fetch && git rebase <remote_name>/<branch_name>
```
