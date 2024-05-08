# DT用例目录结构和脚本

## 目录结构

```bash
设备仓
├── build
│   ├── build.sh
│   └── llt
│       └── compile.sh
├── CI
│   └── script
│       ├── mr_llt_module_compile.sh
│       └── mr_llt_module_gtest.sh
├── src
└── tests
    ├── CMakeLists.txt
    └── llt_module
        ├── CMakeLists.txt
        └── src_linux
            ├── CMakeLists.txt
            ├── testcase.cpp
            └── test_main.cpp
```

## DT测试编译问题

```bash
$WORKSPACE="/home/h30045134/share/LCC/Component/Equipment/system_equip/lcc_system_equip"
$BUILD_CACHE_PATH="buildcache"

set(ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(COMPONENT_PATH ${ROOT_PATH}/Component)
```

## unifybuild

-   统一构建

## buildcache

-   cmake编译过程文件和.a链接库等都在buildcache

-   在此输出构建目录
-   执行cmake
-   输出到output

![image-20230801142549003](http://image.huawei.com/tiny-lts/v1/images/f202a46692196726f01fe7b3c796a715_1253x895.png)

```shell
.
└── LCC
    ├── build
    │   ├── buildConfig.xml
    │   ├── compile.sh
    │   ├── create_weak_password.py
    │   ├── dependency.xml
    │   ├── download_dependency.sh
    │   ├── emap.cfg
    │   ├── init_cert
    │   ├── init_env
    │   ├── package.sh
    │   ├── pack_apploadbin
    │   │   ├── apploadbin_template
    │   │   │   ├── common_func.sh
    │   │   │   ├── count_app_length.sh
    │   │   │   ├── create_emap_cfg_file.sh
    │   │   │   ├── create_pullup_script.sh
    │   │   │   └── template_args.sh
    │   │   ├── network_srv
    │   │   │   ├── network_srv_args.sh
    │   │   │   └── network_srv_func.sh
    │   │   └── web_server
    │   │       ├── web_server_args.sh
    │   │       └── web_server_func.sh
    │   ├── process_ddl_compile.sh
    │   └── process_platform.sh
    ├── cmake
    │   ├── platform
    │   │   ├── common_def.cmake
    │   │   └── find_platform.cmake
    │   ├── product
    │   │   ├── LCCA
    │   │   │   └── app_arm.cmake
    │   │   ├── network_service.cmake
    │   │   └── web_server.cmake
    │   ├── superbuild
    │   │   └── CMakeLists.txt
    │   └── top_config.cmake
    ├── CMakeLists.txt
    ├── README.md
    ├── src
    │   ├── common
    │   │   ├── cert
    │   │   │   ├── cert_private_key.cpp
    │   │   │   └── cert_private_key.h
    │   │   ├── common_function
    │   │   │   ├── common_function.cpp
    │   │   │   └── common_function.h
    │   │   └── dopra
    │   │       ├── dopra_init.cpp
    │   │       ├── dopra_init.h
    │   │       └── dopra_tick.cpp
    │   ├── network_service_init
    │   │   ├── app_plugin_main
    │   │   │   ├── app_plugin_main.cpp
    │   │   │   ├── app_plugin_main.h
    │   │   │   └── CMakeLists.txt
    │   │   ├── bin_plugin
    │   │   │   ├── bin_process_config.cpp
    │   │   │   ├── bin_process_config.h
    │   │   │   └── CMakeLists.txt
    │   │   ├── CMakeLists.txt
    │   │   └── network_service
    │   │       ├── app_plugin_cfg.h
    │   │       ├── CMakeLists.txt
    │   │       └── network_service_init.cpp
    │   ├── system_init
    │   │   ├── ate_mgr_cfg
    │   │   │   ├── ate_mgr_cfg.cpp
    │   │   │   ├── ate_mgr_cfg.h
    │   │   │   └── CMakeLists.txt
    │   │   ├── CMakeLists.txt
    │   │   ├── comp_init.cpp
    │   │   ├── comp_init.h
    │   │   ├── emap_config.cpp
    │   │   ├── emap_config.h
    │   │   ├── emap_config_param.cpp
    │   │   ├── emap_config_param.h
    │   │   ├── equip_factory
    │   │   │   ├── CMakeLists.txt
    │   │   │   ├── equip_factory.cpp
    │   │   │   ├── equip_factory.h
    │   │   │   ├── factory_cfg.cpp
    │   │   │   └── factory_cfg.h
    │   │   ├── main.cpp
    │   │   ├── system_init.cpp
    │   │   ├── system_init.h
    │   │   ├── vrl_cfg
    │   │   │   ├── CMakeLists.txt
    │   │   │   ├── vrl_cfg.cpp
    │   │   │   └── vrl_cfg.h
    │   │   └── web_res
    │   │       ├── CMakeLists.txt
    │   │       ├── web_res.cpp
    │   │       └── web_res.h
    │   └── web_server_init
    │       ├── CMakeLists.txt
    │       ├── web_page_config.cpp
    │       ├── web_page_config.h
    │       ├── web_process_config.cpp
    │       ├── web_process_config.h
    │       ├── web_process_main.cpp
    │       ├── web_process_product.cpp
    │       ├── web_process_product.h
    │       ├── web_process_res.cpp
    │       └── web_process_res.h
    ├── VersionSet.xml
    └── version.xml
```

## DT

-   相对路径修改

```C++
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/9/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:hsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-9-Av3uEd/gcc-9-9.4.0/debian/tmp-nvptx/usr,hsa --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```

