#include <iostream>
int i = 3;
namespace A {
    int i = 1;
}

namespace B {
    int i = 2;
    void F1(void);
    void F2(void);
    void F3(void);
    void F4(void);
}

void B::F1(void) {
    using namespace A;
    std::cout << i << std::endl;
}

void B::F2(void) {
    using A::i;
    std::cout << i << std::endl;
}

void B::F3(void) {
    std::cout << A::i << std::endl;
}

void B::F4(void) {
    std::cout << i << std::endl;
}

/**
 * 2
 * 1
 * 1
 * 2
*/
int main() {
    using namespace B;
    F1();
    F2();
    F3();
    F4();
    return 0;
}