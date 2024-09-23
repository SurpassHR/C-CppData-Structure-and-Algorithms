#include "../LeetCode.h"

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }

        return ans > INT32_MAX || ans < INT32_MIN ? 0 : ans;
    }
};

class Solution1 {
public:
    int reverse(int x) {
        if (x == INT32_MAX || x == INT32_MIN) return 0;
        int ans = 0;
        int i;
        int sign;
        if (x > 0) sign = 1;
        else if (x < 0) sign = -1;
        else sign = 0;
        x = abs(x);

        // 最大32位整型的位数
        int intMax = INT32_MAX;
        int intMin = INT32_MIN;
        vector<int> intMaxArr, intMinArr;
        while (intMax != 0) {
            intMaxArr.insert(intMaxArr.end(), intMax % 10);
            intMax /= 10;
        }
        while (intMin != 0) {
            intMinArr.insert(intMinArr.end(), abs(intMin % 10));
            intMin /= 10;
        }

        // 存储位数
        vector<int> bits;
        while (x != 0) {
            bits.insert(bits.begin(), x % 10);
            x /= 10;
        }
        int size = bits.size();
        bits.resize(intMaxArr.size());

        for (int it : bits) cout << it << " ";
        cout << endl;

        // 判断溢出
        if (size > intMaxArr.size() || size > intMinArr.size()) return 0;
        else {
            for (i = intMaxArr.size() - 1; i >= 0; i--) {
                if (bits[i] < intMaxArr[i]) break;
                if (sign > 0 && bits[i] > intMaxArr[i]) {
                    return 0;
                } else if (sign < 0 && bits[i] > intMinArr[i]) {
                    return 0;
                }
            }
        }

        // 规范化数
        int exp = 1;
        for (i = 0; i < size; i++) {
            ans += exp * bits[i];
            if (exp >= 1000000000) break;
            exp *= 10;
        }
        ans *= sign;

        if (size < intMaxArr.size()) return ans;

        return ans;
    }
};

int main(void) {
    Solution sl;
    int ans;
    // ans = sl.reverse(1534236469);
    // cout << ans << endl;
    Solution1 sl1;
    ans = sl1.reverse(-2147483648);
    cout << INT32_MIN << endl;
    cout << ans << endl;


    return 0;
}
