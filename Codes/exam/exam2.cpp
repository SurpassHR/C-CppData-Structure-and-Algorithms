#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        std::cout << "Destroy Base" << std::endl;
    }
};

class Derive1:public Base {
public:
    ~Derive1() {
        std::cout << "Destroy Derive1" << std::endl;
    }
};

class Derive2: public Derive1 {
public:
    ~Derive2() {
        std::cout << "Destroy Derive2" << std::endl;
    }
};

int main() {
    Derive1* pObj = new Derive2();
    delete pObj;
    return 0;
}

/***
 * Destroy Derive2
 * Destroy Derive1
 * Destroy Base
*/