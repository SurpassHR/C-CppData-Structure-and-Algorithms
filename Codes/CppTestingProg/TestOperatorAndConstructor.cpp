//
// Created by h30045134 on 2024/9/23.
//

#include <iostream>
using namespace std;

class Foo {
public:
    Foo() = default;
    Foo(const Foo& foo) {
        cout<<"复制构造函数:Foo(const Foo& foo)"<<endl;
    }
    Foo(Foo&& foo) {
        cout<<"移动构造函数:Foo(Foo&& foo)"<<endl;
    }
    Foo& operator=(const Foo &foo) {
        cout<<"赋值运算符:Foo& operator=(const Foo &foo)"<<endl;
        return *this;
    }
    Foo& operator=(Foo &&foo) {
        cout<<"移动赋值运算符:Foo& operator=(Foo &&foo)"<<endl;
        return *this;
    }

};

Foo GetFoo()
{
    Foo foo;
    return foo;
}

void Pass(Foo foo)
{
    ;
}

Foo PassAndReturn(Foo foo)
{
    return foo;
}

int main()
{
    Foo foo1, foo2;
    cout<<"--------------------------------"<<endl<<"1:\n";
    foo1 = GetFoo();
    cout<<"--------------------------------"<<endl<<"2:\n";
    foo2 = foo1;
    cout<<"--------------------------------"<<endl<<"3:\n";
    foo2 = PassAndReturn(foo1);
    cout<<"--------------------------------"<<endl<<"4:\n";
    Pass(foo1);
    cout<<"--------------------------------"<<endl<<"5:\n";
    Foo foo3 = PassAndReturn(foo1);
    cout<<"--------------------------------"<<endl;
    return 0;
}
