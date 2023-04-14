// Object Oriented Program
#include <iostream>
#include <stdio.h>
using namespace std;

class A {
   public:
    // int a;
    int i;
    A();
    ~A();
    void f();
};

A::A() {
    printf("A的构造函数\n");
}

A::~A() {
    printf("A的析构函数\n");
}

void A::f() {
    printf("&(this->i) = %p\n", &(this->i));
}

int main(void) {
    printf("大括号之前\n");
    {
        printf("创建a\n");
        A a;
        printf("&a = %p\n", &a);
        printf("&a.i = %p\n", &(a.i));
        a.f();
        printf("创建b\n");
        A b;
        printf("&b = %p\n", &b);
        printf("&b.i = %p\n", &(b.i));
        b.f();
    }
    printf("大括号之后\n");
    return 0;
}
