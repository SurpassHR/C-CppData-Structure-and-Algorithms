## 编译&执行 DT 用例

- 通过脚本一键解决（在编译服务器的 `~/.bashrc` 添加以下内容）:

```bash
# 全局路径配置
export LCC_ROOT=/path/to/your/code/root # 修改为自己的代码路径
export TEMP_SCH_ROOT=${LCC_ROOT}/Component/CommonServiceComponent/temp_ctrl_schedule

# 寻找脚本文件并执行
findexec() {
    find $1 -type $2 -name $3 -exec bash {} \;
}

# 寻找文件并删除
finddel() {
    find $1 -type $2 -name $3 -exec rm -rf {} \; > /dev/null
}

# 编译和执行 DT
compile_run_dt() {
    findexec ${TEMP_SCH_ROOT} f compile.sh
    findexec ${TEMP_SCH_ROOT} f mr_llt_module_gtest.sh
}

# 清理临时输出件（git add 前使用）
compile_clean() {
    finddel ${LCC_ROOT} f build_linuxDTCenter.xml
    finddel ${LCC_ROOT} f *_llt_bin
    finddel ${LCC_ROOT}/CI d output
    finddel ${LCC_ROOT}/Component d build_linux
    finddel ${LCC_ROOT}/Component d buildcache
}

remove_output() {
    finddel ${LCC_ROOT}/Component/CommonServiceComponent d output
    finddel ${LCC_ROOT}/Component/Equipment d output
    finddel ${LCC_ROOT}/Equip_Model_Tools d __pycache__
    finddel ${LCC_ROOT}/PublicProduct/LCC/build f dependency.xml.md5
}

# 【快捷指令】增量编译和运行 DT
alias dt=compile_run_dt
```

## 查看覆盖率

-   下载 [static-html-server](https://codehub-y.huawei.com/v1/projects/3064516/repository/blobs/69326f7610dd51742b16b5afaa03a4f0bb7727a8/raw?file_name=static-html-server) 到服务器的 `~` 目录下

```bash
# 执行覆盖率分析
gen_lcov() {
	cd ~; rm -rf coverage_html/; rm -rf coverage_report.tar coverage.info coverage_all.info ; /usr/local/bin/lcov --rc lcov_branch_coverage=1 --gcov-tool=/usr/bin/gcov -c -o coverage_all.info -d ${TEMP_SCH_ROOT} --ignore-errors=graph; /usr/local/bin/lcov --rc lcov_branch_coverage=1 --gcov-tool=/usr/bin/gcov --extract coverage_all.info '*' -o coverage.info --ignore-errors=graph; /usr/local/bin/genhtml --rc lcov_branch_coverage=1 coverage.info -o coverage_html/ --show-details --legend --ignore-errors=source; cd -;
}

export HTML_PORT=11223
export COV_ROOT=~/coverage_html

# 生成覆盖率静态页面，使用方法: gen_static_lcov_html {自定义端口号}
gen_static_lcov_html() {
	html_port=$1
	chmod +x ~/.local/share/code-server/extensions/nextcode.dtcenter-1.8.12/tools/static-html-server; ~/.local/share/code-server/extensions/nextcode.dtcenter-1.8.12/tools/static-html-server --root=${COV_ROOT} --port=${html_port}
}

# 【快捷指令】生成覆盖率报告并将页面发布到本地端口
alias lcov="gen_lcov && gen_static_lcov_html ${HTML_PORT}"

# 获取覆盖率展示地址
get_lcov_html_addr() {
	ip=$(hostname -I | sed 's/ *$//')
	echo "http://$ip:$HTML_PORT"
	# xdg-open "http://$ip:$HTML_PORT" # 若 server 为 WSL2 的话则可以直接打开该页面
}

# 【快捷指令】获取/打开本地覆盖率展示网页
alias addr=get_lcov_html_addr
```

-   单个 DT 用例执行

```bash
# 单条用例执行
single_dt() {
	/home/h30045134/code/LCC/Component/CommonServiceComponent/temp_ctrl_schedule/tests/llt_module/build_linux/comp_temp_ctrl_schedule_llt_bin --gtest_catch_exceptions=1 --gtest_filter=$1
}

# 【快捷指令】单个DT用例执行，入参: 用例所属类.用例名，如: sdt TestLogicCompModule.test_comp_module_vacuumizing_ctrl_proc_ctrl
alias sdt="single_dt"
```

