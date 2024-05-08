#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // n组样例
    int n = 0;
    cin >> n;
    // 循环输入
    int cnt = 0;
    while (cnt < n) {
        string A, B, sum;
        cin >> A >> B;
        int len = max(A.size(), B.size());
        // 将大数录入数组中
        int a[len] = { 0 }, b[len] = { 0 };
        for (int i = A.size() - 1; i >= 0; i--) a[i + len - A.size()] = A[i] - '0';
        for (int i = B.size() - 1; i >= 0; i--) b[i + len - B.size()] = B[i] - '0';
        // for (int i = 0; i < len; i++) cout << a[i] << " ";
        // cout << "\n";
        // for (int i = 0; i < len; i++) cout << b[i] << " ";
        // cout << "\n";
        // 高精度计算
        int carry = 0, val = 0;
        for (int i = len - 1; i >= 0; i--) {
            val = a[i] + b[i] + carry;
            carry = val / 10;
            val %= 10;
            // 使用字符串存储数字位数
            sum.insert(sum.begin(), val + '0');
        }
        cout << "Case " << cnt + 1 << ":\n"
            << A << " + " << B << " = ";
        if (carry) cout << carry;
        cout << sum << "\n\n";
        cnt++;
    }
    return 0;
}
