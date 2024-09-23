#include <iostream>
using namespace std;

class VirtualMachine1 {
public:
    VirtualMachine1(int id) : m_id(id) { }

private:
    int m_id;
    int m_load { 0 };
};

class VirtualMachine2 {
public:
    explicit VirtualMachine2(int id) : m_id(id) { }

private:
    int m_id;
    int m_load { 0 };
};

class VirtualMachine3 {
public:
    explicit VirtualMachine3(int id, int seq) : m_id(id), m_seq(seq) { }

private:
    // 成员变量初始化列表初始化
    int m_id;
    int m_seq;

    int m_load { 0 }; // 定义时初始化，花括号初始化C++11新特性 C++11以前int m_load = 0;向上兼容
};

class VirtualMachine4 {
public:
    // 赋值语句初始化成员变量
    explicit VirtualMachine4(int id, int seq) {
        this->m_id = id;
        this->m_seq = seq;
    }

private:
    int m_id;
    int m_seq;
    int m_load { 0 };
};

class Foo {
public:
    Foo(int i) { }
    explicit Foo(char c) = delete;
};

void Func(Foo foo) {
    return;
}

int main() {
    int vm1_id = 42;
    int vm2_id = 43;
    VirtualMachine1 vm1 = vm1_id;
    VirtualMachine2 vm2 = static_cast<VirtualMachine2>(vm2_id);

    return 0;
}
