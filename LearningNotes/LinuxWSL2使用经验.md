## 取消 bash 自动补全的大小写敏感

-   在当前账户启用：在 `~/.inputrc` 添加 `set completion-ignore-case on`
-   全局启用：在 `/etc/inputrc` 添加 `set completion-ignpre-case on`

## 账户相关

-   root 账户下 `useradd -m -d /path/to/user/home ${username}`
-   修改用户密码 `passwd ${username}`
-   在已经创建用户家目录的情况下修改家目录 `usermod -d /path/to/new/user/home/ ${username}`
-   查看当前正在使用的用户会话 `w`
-   杀死用户会话 `sudo pkill -KILL -u ${username}`
-   删除用户 `sudo userdel -r ${username}`

## Samba

-   在服务器为账户添加 Samba 服务配置
    -   编辑 `/etc/samba/smb.conf` ，添加以下配置

```ini
[h30045134]
  comment = h30045134
  path = /usr1/h30045134
  writeable = yes
  browseable = yes
  valid users = h30045134
  public = yes
  security=share
```

-   在PC创建远程文件系统连接 `net use <盘符>: \\<服务器IP地址>\path\to\directory <用户密码> /user:<用户名>`

## 设置默认 Shell

-   编辑 `/etc/passwd`

## 为用户增加 root 权限

-   `vim /etc/sudoers`
-   `${user_name} ALL=(ALL:ALL) ALL`