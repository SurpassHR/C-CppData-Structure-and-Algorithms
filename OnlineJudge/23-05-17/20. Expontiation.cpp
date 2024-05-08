#include <iostream>
#include <cmath>
using namespace std;

string mult(string mult1, string mult2) {
    // cout << mult1 << ", " << mult2 << endl;
    string ret = "";
    // 计算 mult1 * mult2
    // cout << "==" << mult1 << " * " << mult2 << "==" << endl;
    for (int i = mult1.size() - 1; i >= 0; i--) {
        int val = 0;  // 乘法当前值
        int carry = 0;  // 乘法进位值
        // 计算 mult1[i] * mult2
        // cout << "=" << mult1[i] << " * " << mult2 << "=" << endl;
        string t = "";
        for (int j = mult2.size() - 1; j >= 0; j--) {
            // 计算 mult1[i] * mult2[j]
            // cout << mult1[i] << " * " << mult2[j] << endl;
            val = (mult1[i] - '0') * (mult2[j] - '0') + carry;
            carry = val / 10;
            val %= 10;
            // 写入临时缓冲区
            t.insert(t.begin(), val + '0');
        }
        // 判断进位写入
        if (carry) {
            t.insert(t.begin(), carry + '0');
        }
        // 当前层的计算结果所需的最小位数
        t.resize(t.size() + mult1.size() - 1 - i, '0');
        // cout << "t = " << t << endl;
        int len = max(t.size(), ret.size());
        t.insert(t.begin(), len - t.size(), '0');
        ret.insert(ret.begin(), len - ret.size(), '0');
        // 计算 t + ret
        int v = 0;  // 加法当前值
        int c = 0;  // 加法进位值
        for (int k = len - 1; k >= 0; k--) {
            v = ret[k] + t[k] - 2 * '0' + c;
            c = v / 10;
            v %= 10;
            ret[k] = v + '0';
        }
        if (c) {
            ret.insert(ret.begin(), c + '0');
        }
        // cout << "ret = " << ret << endl;
    }
    // 删除开头无意义'0'
    auto it = ret.begin();
    while (it != ret.end() && *it == '0') {
        ret.erase(it);
    }
    // cout << "ret = " << ret << endl;
    return ret;
}

int main() {
    string R = "";
    int N = 0;
    while (cin >> R >> N) {
        // 整数逻辑右移位数（从开头到小数点位数）
        int shiftR = 0;
        for (int i = 0; i < R.size(); i++) {
            if (R[i] == '.') {
                shiftR = i;
                break;
            }
        }
        R.erase(shiftR, 1);  // 转换为整数
        shiftR = (R.size() - shiftR) * N;
        // 执行 N 次乘法
        string res = "1";
        for (int i = 0; i < N; i++) {
            res = mult(res, R);
            // cout << res << endl;
        }
        int dotPos = res.size() - shiftR;
        // cout << dotPos << endl;
        if (dotPos >= 0) {
            res.insert(res.begin() + (res.size() - shiftR), '.');
        } else {
            res.insert(res.begin(), -dotPos, '0');
            res.insert(res.begin(), '.');
        }
        // 删除小数末尾无意义'0'
        for (int i = res.size() - 1; res[i] == '0'; i--) {
            res.erase(i);
        }
        cout << res << endl;
    }

    return 0;
}