#include <iostream>

using namespace std;

class Solution {
public:
    int squareRoot(int a) {
        // 因为返回值为整数的平方根算法
        if (a <= 1) return a;
        // 牛顿迭代法
        // 记初始值 x_0 = a / 2
        // 因为 a / 2 一定大于 sqrt(a)
        double x_0 = a / 2;
        double y_0 = x_0 * x_0 - a;
        // 由 y_0 = x_0 ^ 2 - a = 0 得在 (x_0, y_0) 点的切线斜率 k_0 = y'_0 = 2 * x_0
        double k_0 = 2 * x_0;
        // 切线与 x 轴交点 y_0 = k_0 * x_0 + b_0 => b_0 = -k_0 * x_0 + y_0
        double b_0 = -k_0 * x_0 + y_0;
        // 迭代
        while (y_0 > 0.1) {
            // y_0 = k_0 * x_0 + b_0 = 0 => x_0 = -b_0 / k_0
            x_0 = -b_0 / k_0;
            y_0 = x_0 * x_0 - a;
            k_0 = 2 * x_0;
            b_0 = -k_0 * x_0 + y_0;
        }
        return int(x_0);
    }
};

int main() {
    cout << Solution().squareRoot(9) << endl;
    return 0;
}
