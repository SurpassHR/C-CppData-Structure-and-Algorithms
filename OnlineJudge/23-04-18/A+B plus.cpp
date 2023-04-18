#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // n组样例
    int n = 0;
    cin >> n;
    // 循环输入
    while (n > 0) {
        string A, B, sum;
        cin >> A >> B;
        // 将大数录入数组中
        int a[A.size()] = { 0 }, b[B.size()] = { 0 };
        for (int i = 0; i < A.size(); i++) a[i] = A[i];
        for (int i = 0; i < B.size(); i++) b[i] = B[i];
        // 高精度计算
        int carry = 0, val = 0, len = max(A.size(), B.size());
        for (int i = 0; i < len; i++) {
            val = a[i] + b[i] + carry - 2 * '0';
            carry = val / 10;
            val %= 10;
            // 使用字符串存储数字位数
            sum.push_back(val + '0');
        }
        if (carry) cout << carry;
        cout << sum << endl;
        n--;
    }
    return 0;
}
