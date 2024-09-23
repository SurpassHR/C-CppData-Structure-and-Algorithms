#include <iostream>
using namespace std;

class Base {
public:
    virtual void Display() const {
        std::cout << "I am Base class !" << std::endl;
    }
    virtual ~Base() = default;
};
class Derive: public Base {
public:
    virtual void Display() {
        std::cout << "I am Derive class !" << std::endl;
    }
    virtual ~Derive() = default;
};

/**
 * I am Base class !
 * I am Derive class !
*/
int main() {
    const Base* base = new Derive();
    Derive* derive = new Derive();
    base->Display();
    derive->Display();
    delete base;
    delete derive;
    return 0;
}