#include <iostream>

using namespace std;

// 继承: inherit
// 多态: polymorphism

/*
    1.继承的写法
        子类: 继承 父类
        {

        }
        继承方式: public protected private
    2.继承中构造函数写法
        子类的构造函数必须调用父类的构造函数
    3.权限问题
*/

class MM {
public:
    MM(string name, int age): name(name), age(age) { }
    void print() {
        cout << "MM:" << name << ":" << age << endl;
    }
protected:
    string name;
    int age;
};

// 继承子类写法
// public: 最低权限 protected private: 最高权限
class boy:public MM {
public:

};

class Test {
protected:
    string name;
public:
    string getName() {
        return this->name;
    }
    void printName() {
        cout << name << endl;
    }
};

class SmallTest:private Test {
public:
    void printName() {
        cout << name << endl;
    }
};

int main() {
    MM mm("MM", 18);
    mm.print();
    Test test;
    test.printName();

    return 0;
}
