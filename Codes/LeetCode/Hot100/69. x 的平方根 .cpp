#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // x == 0 || x == 1
        if (x <= 1) return x;
        // 要求：y_0 = x_0 ^ 2 与 y = x 的交点 x_0 = sqrt(x)
        // 即求：y_0 = x_0 ^ 2 - a = 0
        // 初始化近似值 x_0
        double x_0 = x / 2;
        // 切点纵坐标
        double y_0 = x_0 * x_0 - x;
        // 切点斜率
        double k = 2 * x_0;
        // 切线截距
        double b = -k * x_0 + y_0;
        while (y_0 > 0.01) {
            cout << x_0 << endl;
            x_0 = -b / k;
            y_0 = x_0 * x_0 - x;
            k = 2 * x_0;
            b = -k * x_0 + y_0;
        }
        cout << x_0 << endl;
        return int(x_0);
    }
};

int main() {
    int ans = Solution().mySqrt(9);
    cout << ans << endl;

    return 0;
}
