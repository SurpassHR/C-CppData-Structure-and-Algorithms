#include <bits/stdc++.h>

class Parent {
public:
    Parent() { Print(); } // 纯虚函数不能在基类构造函数调用，因为构造时先执行基类的构造，此时虚函数表还未初始化完成
    // 但是基类的纯虚函数可以在正常执行过程中调用，当然前提是子类重写了纯虚函数的实现
    virtual ~Parent() {}

private:
    virtual void Print() = 0;
};

class Son : public Parent {
public:
    Son() { Print(); }
    ~Son() {}

private:
    void Print() override { std::cout << "2" << "\n"; }
};

int main()
{
    Parent *p = new Son;
    delete p;
    return 0;
}