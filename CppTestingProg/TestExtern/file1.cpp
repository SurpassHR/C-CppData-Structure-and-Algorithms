#include <iostream>

// 声明外部变量
extern int count;

void printCount() {
    std::cout << "Count in file1: " << count << std::endl;
}

// 定义一个全局对象，用于调用printCount函数
struct InitializerA {
    InitializerA() {
        printCount();
    }
};

// 实例化全局对象
InitializerA initA;
