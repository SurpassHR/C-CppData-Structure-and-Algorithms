#include <iostream>
using namespace std;

/**
 * Hello
 * 2, 2
*/
int main() {
    int x = 1, y = 2;

    if (++x >= 2 || y++ >= 2) {
        cout << "Hello" << endl;
    }
    cout << x << ", " << y << endl;
    return 0;
}