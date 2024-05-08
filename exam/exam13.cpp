#include<iostream>
#include<functional>
using namespace std;
auto g1(int x) {
    return [&x](int y) {return x + y;};
}
auto g2(int& x) {
    return [&x](int y) {return x + y;};
}

/**
 * 6422018, 3
 * 6422018, 4
*/
int main() {
    int x = 1;
    auto f1 = g1(x);
    auto f2 = g2(x);

    cout << f1(2) << ", " << f2(2) << endl;

    x = 2;
    cout << f1(2) << ", " << f2(2) << endl;
    return 0;
}