//
// Created by h30045134 on 2024/9/24.
//

#include <iostream>

int Foo();
int Gear();
int Smith();

// 以下4个全局变量中，g_alice、g_bob、g_smith都存储在bss段，属于未初始化的全局变量
int g_alice = Foo(); // 在Foo()中获取g_bob的值，g_bob作为全局变量，在g_alice之后初始化，未初始化的全局变量会被默认初始化为0
int g_bob = Gear();
int g_mike = 4;
int g_smith = Foo();

int Foo()
{
    std::cout << "Foo" << std::endl;
    return g_bob;
}

int Gear()
{
    std::cout << "Gear" << std::endl;
    return 3;
}

int main()
{
    // 由于g_alice需要在g_bob初始化之前获取其值，获取到的是未初始化全局变量的默认初始值0
    std::cout << g_alice;
    // 而g_smith在g_bob初始化之后才获取其值，获取到的是g_bob初始化之后的值
    std::cout << g_smith;
    return 0;
}