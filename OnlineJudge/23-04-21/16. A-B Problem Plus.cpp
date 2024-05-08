#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

// BUG做法
// int main() {
//     int T = 0;
//     cin >> T;
//     int cnt = 0;
//     string A = "";
//     string B = "";
//     while (cnt < T) {
//         cin >> A >> B;
//         // 将字符串转换为数组
//         int len = max(A.size(), B.size());
//         int a[len] = { 0 }, b[len] = { 0 };
//         for (int i = 0; i < len; i++) a[i + len - A.size()] = A[i] - '0';
//         for (int i = 0; i < len; i++) b[i + len - B.size()] = B[i] - '0';
//         // 模拟减法
//         int val = 0;
//         int borrow = 0;
//         string sum = "";
//         for (int i = len - 1; i >= 0; i--) {
//             val = a[i] - b[i] - borrow;
//             borrow = val < 0 ? 1 : 0;
//             val += borrow * 10;
//             sum.insert(sum.begin(), val + '0');
//         }
//         cout << "Case " << cnt + 1 << ":" << endl;
//         cout << A << " - " << B << " = "
//             << fixed << setprecision(0) << (atoi(&sum[0]) - pow(10, len) * borrow) << "\n" << endl;
//         cnt++;
//     }
//     return 0;
// }

bool isGreaterEqual(string A, string B) {
    if (A.size() > B.size()) {
        return true;
    } else if (A.size() < B.size()) {
        return false;
    } else {
        return A.compare(B) >= 0 ? true : false;
    }
}

string bigNumMinus(string A, string B) {
    // 转为数组
    vector<int> a(0), b(0);
    a.assign(A.begin(), A.end());
    b.assign(B.begin(), B.end());
    for (auto it = a.begin(); it != a.end(); it++) *it -= '0';
    for (auto it = b.begin(); it != b.end(); it++) *it -= '0';
    int len = max(a.size(), b.size());
    for (int i = a.size(); i < len; i++) a.insert(a.begin(), 0);
    for (int i = b.size(); i < len; i++) b.insert(b.begin(), 0);
    // 模拟减法
    string diff = "";
    int borrow = 0;
    int val = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (borrow) a[i] -= borrow;
        if (a[i] < b[i]) borrow = 1;
        else borrow = 0;
        val = a[i] - b[i] + 10 * borrow;
        diff.insert(diff.begin(), val + '0');
    }
    // 去掉开头的0
    auto it = diff.begin();
    while (*it == '0') diff.erase(it);

    return diff;
}

int main() {
    int T = 0;
    cin >> T;
    int cnt = 0;
    string A = "";
    string B = "";
    string res = "";
    while (cnt < T) {
        cin >> A >> B;
        if (A.compare(B) == 0) {
            res = "0";
            goto Output;
        }
        // 始终保持大数减小数
        if (isGreaterEqual(A, B)) {
            res = bigNumMinus(A, B);
        } else {
            res = '-' + bigNumMinus(B, A);
        }
    Output:
        cout << "Case " << cnt + 1 << ":" << endl;
        cout << A << " - " << B << " = ";
        cout << res << "\n" << endl;
        cnt++;
    }

    return 0;
}
