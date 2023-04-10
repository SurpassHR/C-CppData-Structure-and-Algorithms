#include <iostream>

using namespace std;

int main() {
    int n = 0;
    while (cin >> n) {
        if (n == 0) break;
        int drinked = 0;
        while (n >= 3) {
            drinked += n / 3;
            // 剩余的瓶子有 n % 3 + n / 3
            n = n % 3 + n / 3;
        }
        if (n == 2) drinked++;
        printf("%d\n", drinked);
    }
    return 0;
}
