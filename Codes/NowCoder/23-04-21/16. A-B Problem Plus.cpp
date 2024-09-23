#include <iostream>
#include <vector>
using namespace std;

bool isGreaterEqual(string A, string B) {
    if (A.size() > B.size()) {
        return true;
    } else if (A.size() < B.size()) {
        return false;
    } else {
        return A.compare(B) >= 1 ? true : false;
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
    a.resize(len, 0);
    b.resize(len, 0);
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
    while (cnt < T) {
        cin >> A >> B;
        // 始终保持大数减小数
        string res = "";
        if (isGreaterEqual(A, B)) {
            // execute A - B
            res = bigNumMinus(A, B);
        } else {
            // execute B - A
            res = '-' + bigNumMinus(B, A);
        }
        cout << res << endl;
        cnt++;
    }
}
