// #include <bits/stdc++.h>
#include <iostream>
#include "TestOverrideNew.h"

class TestClass {
public:
    TestClass() : data(new char[100]) {
        std::cout << "TestClass constructed\n";
    }
    ~TestClass() {
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