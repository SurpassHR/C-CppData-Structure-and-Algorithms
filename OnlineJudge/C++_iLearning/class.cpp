#include <iostream>
using namespace std;

class Base {
public:
    int a;
    void setA(int val);
    void setB(int val);
    int getB();
    int getC();

private:
    int b;

protected:
    int c;
};

void Base::setA(int val)
{
    b = val;
}

void Base::setB(int val)
{
    c = val;
}

int Base::getB()
{
    return b;
}

int Base::getC()
{
    return c;
}

// class derive : public Base {
// public:
//     void printParameters()
//     {
//         cout << a << endl;
//         cout << b << endl;
//         cout << c << endl;
//     }
// };

int main()
{
    Base base;
    base.a = 1;
    base.setA(2);
    base.setB(3);
    cout << "a = " << base.a << ", b = " << base.getB() << ", c = " << base.getC() << endl;
    return 0;
}