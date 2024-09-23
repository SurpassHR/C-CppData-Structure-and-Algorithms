#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f[50] = { 0 };
    int Fibonacci(int n) {
        if (n <= 2) return 1;
        if (f[n] > 0) return f[n];
        return f[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    }

    int test(int n) {
        int a;
        // = 的返回值为被赋的值
        // a = 5; 的返回值为 5
        return a = n;
    }
};

int main() {
    Solution sl;
    int ans = sl.Fibonacci(4);
    cout << ans << endl;
    ans = sl.test(4);
    cout << ans << endl;
    return 0;
}
