// #include <bits/stdc++.h>
#include <iostream>
#include "TestOverrideNew.h"

extern int wasd;
extern int qwer;

struct initConst {
    initConst() {
        std::cout << wasd << "\t" << qwer << "\n";
    }
};

initConst asdasd;

class TestClass {
public:
    TestClass() : data(new char[100]) {
        std::cout << "wasd: " << wasd << "\n";
        std::cout << "TestClass constructed\n";
    }
    ~TestClass() {
        std::cout << "qwer: " << qwer << "\n";
        DELETE[] data;
        std::cout << "TestClass destructed\n";
    }
private:
    char* data;
};

int main() {
    volatile TestClass* obj = NEW TestClass();
    DELETE obj;

    volatile int* intPtr = NEW int(10);
    DELETE intPtr;

    return 0;
}