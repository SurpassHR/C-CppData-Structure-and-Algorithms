//
// Created by h30045134 on 2024/10/9.
//

#include <bits/stdc++.h>
using namespace std;

void test()
{
    char str[10];
    std::cin.get(str, 5, 'd');
    std::cout << str << std::endl;
}

class Base {
public:
    Base(int a) : varA(a) {}
    int varA;
};

class Derived : public Base {
public:
    int varB;
    int varC;
    Derived(int a, int c) : varC(c), Base(a), varB(varA + varC) {}
};
Derived derived(1, 10);

void rev()
{
    char c = cin.get();
    if (c != '\n') {
        rev();
    }
    cout << c;
}

double Up(double x) { return 2.0 * x; }
void R1(const double &rx) { cout << "const double & rx" << endl; }
void R1(double &&rx) { cout << "double && rx" << endl; }

struct Complex {
    int real;
    int imag;
};

void Function(Complex c) {
    cout << "Complex" << endl;
    cout << c.real << "," << c.imag << endl;
}

class Base1 {
public:
    static int count;
};

int Base1::count = 5;

class Derived1 : public Base1 {};

class MyClass {
public:
    explicit MyClass(int num) : number(num) {}
    friend MyClass operator*(const MyClass& left, const MyClass& right) {
        return MyClass(left.number * right.number);
    }
    MyClass operator*(const MyClass &rhs) const {
        return MyClass(this->number * rhs.number);
    }
    int number;
};

int main()
{
//    std::unique_ptr<int> up(new int());
//    std::unique_ptr<int> up1 = new int();
//    std::unique_ptr<int> p;
//    std::unique_ptr<int> up2(p);
//    test();
//    cout << derived.varA << ", " << derived.varB << ", " << derived.varC << "\n";
//    rev();
//    cout << "Alpha\0asdasd";
//    atomic<uint32_t> myAto(0);
//    ++myAto;
//    cout << myAto.exchange(0);
//    cout << myAto;
//    double alpha[][4] = {{0}, {1, 2}, {3, 4, 5}};
//    cout << sizeof(alpha) / sizeof(double);
//    double w = 10.0;
//    R1(w + 1);
//    R1(Up(w));

//    Function({1, 2});
//    Base1 b;
//    cout << b.count;
//    cout << Derived1::count;
//    Derived1 a;
//    cout << a.count;
//    cout << Base1::count;
    MyClass alice(2);
    MyClass bob(3);
//    auto product = operator*(alice, bob);
//    auto product = alice * bob;
//    auto product = bob * alice;
    auto product = alice.operator*(bob);
    cout << product.number;
}


