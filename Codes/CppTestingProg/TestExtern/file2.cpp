#include <iostream>

// 定义一个全局变量
int count = 10;

void initialize() {
    std::cout << "Initializing count to 20 in file2" << std::endl;
    count = 20;
}

// 定义一个全局对象，用于调用initialize函数
struct InitializerB {
    InitializerB() {
        initialize();
    }
};

// 实例化全局对象
InitializerB initB;
