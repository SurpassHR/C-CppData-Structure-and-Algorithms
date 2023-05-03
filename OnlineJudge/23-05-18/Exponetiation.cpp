#include <iostream>
#include <cmath>
using namespace std;

string mult(string mult1, string mult2) {
    string ret = "";
    // 按位计算mult1 * mult2
    cout << "\n=calc " << mult1 << " * " << mult2 << "=" << endl;
    for (int i = mult1.size() - 1; i >= 0; i--) {
        cout << "calc " << mult1[i] << " * " << mult2 << endl;
        string t = "";  // 临时变量存储 mult1[i] * mult2
        int val = 0;  // 单步乘法当前值
        int carry = 0;  // 单步乘法进位值
        for (int j = mult2.size() - 1; j >= 0; j--) {
            val = (mult1[i] - '0') * (mult2[j] - '0') + carry;
            carry = val / 10;
            val %= 10;
            // 写入到临时缓冲区
            t.insert(t.begin(), val + '0');
        }
        // 写入进位值
        if (carry) {
            t.insert(t.begin(), carry + '0');
        }
        // 补齐进位
        t.resize(t.size() + mult1.size() - 1 - i, '0');
        // 当前计算所需的最小位数
        int len = max(ret.size(), t.size());
        // 不够最小长度的在末尾补齐'0'
        t.insert(t.begin(), len - t.size(), '0');
        ret.insert(ret.begin(), len - ret.size(), '0');
        // t 和 ret 按位相加
        int c = 0;  // 加法进位值
        int v = 0;  // 加法当前值
        for (int k = len - 1; k >= 0; k--) {
            v = t[k] + ret[k] - 2 * '0' + c;
            c = v / 10;
            v %= 10;
            // 写入到ret
            ret[k] = v + '0';
        }
        if (c) {
            ret.insert(ret.begin(), c + '0');
        }
        for (int i = ret.size() - 1; i >= 0; i--) {
            if (ret[i] != '0') {
                break;
            }
            ret.erase(i);
        }
        cout << ret << endl;
    }
    auto it = ret.begin();
    while (*it == '0') {
        ret.erase(it);
    }

    return ret;
}

int main() {
    string R = "";  // 浮点数
    int N = 0;  // 指数
    cin >> R >> N;

    // 得到整数右移位数
    int shiftR = 0;
    for (int i = R.size() - 1; i >= 0; i--) {
        if (R[i] == '.') {
            shiftR = i;
            break;
        }
    }
    // 还原为整数
    R.erase(shiftR, 1);
    // 最终结果右移位数
    shiftR = pow(shiftR, N);

    // 计算指数
    int i = 0;
    string res = "1";
    while (i < N) {
        // 计算一次乘法
        res = mult(res, R);
        cout << res << endl;
        i++;
    }


    return 0;
}
