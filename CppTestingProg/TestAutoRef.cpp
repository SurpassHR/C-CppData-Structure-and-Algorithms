#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A() {}
    ~A()
    {
        printf("destructor\n");
    }
};

void test(A &a)
{
    auto aa = a;
}

int main()
{
    A a;
    test(a);
    return 0;
}