#include <iostream>

using namespace std;

int main() {
    // 输入十进制数字m和进制n
    double m = 0;
    int n = 0;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) break;
        // 分别取到十进制数字整数部分和小数部分
        int int_part = m / 1; double double_part = m - double(int_part);
        // 整数部分转换为n进制
        int nBaseIntPart = 0;
        // cout << "123" << endl;
        while (int_part > 0) {
            nBaseIntPart = nBaseIntPart * 10 + int_part % n;
            int_part /= n;
        }
        // 小数部分转换为n进制
        // 保留十位小数
        int bits = 10;
        string nBaseDoublePart = "";
        while (bits > 0) {
            double_part *= n;
            // 得到double_part整数部分
            int add = double_part / 1;
            // 得到double_part小数部分
            double_part = double_part - add;
            nBaseDoublePart += '0' + add;
            bits--;
        }
        cout << nBaseIntPart << "." << nBaseDoublePart << endl;
    }
    return 0;
}