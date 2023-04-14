#include <iostream>

// using namespace std;

struct st {
    int a, b;
    /* 构造函数与结构体同名 */
    st(): a(0), b(0) { }
    st(int _a, int _b): a(_a), b(_b) { }
};

int main() {
    st newSt1 = st();
    st newSt2 = st(1, 2);
    std::cout << newSt1.a << newSt1.b << std::endl;
    std::cout << newSt2.a << newSt2.b << std::endl;

    return 0;
}
