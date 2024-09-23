#include <iostream>
using namespace std;
class Base {
public:
    Base() {
        cout << "Base()";
    }
    ~Base() {
        cout << "~Base()";
    }
};

class Subs: public Base {
public:
    Subs() {
        cout << "Subs()";
    }
    ~Subs() {
        cout << "~Subs()";
    }
};

int main() {
    Subs s;
    return 0;
}