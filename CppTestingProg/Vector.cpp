#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    A() = default;
    A(const A& other) {
        cout << "copy constructed" << endl;
    }
    A(A&& other) {
        cout << "move constructed" << endl;
    }
    A& operator = (const A& other) {
        cout << "copy assigned" << endl;
        return *this;
    }
    A& operator = (A&& other) {
        cout << "move assigned" << endl;
        return *this;
    }
};

int main() {
    vector<A> v(1);
    v.reserve(v.capacity() + 1);
    cout << v.capacity() << endl;
    return 0;
}
