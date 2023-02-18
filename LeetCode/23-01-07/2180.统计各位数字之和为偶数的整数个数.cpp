/*
 * @lc app=leetcode.cn id=2180 lang=cpp
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

// @lc code=start
class Solution {
   public:
    int countEven(int num) {
        int count = 0;
        int i;
        for (i = 1; i <= num; i++) {
            int sum = 0;
            int cur = i;
            while (cur != 0) {
                sum += cur % 10;
                cur /= 10;
            }

            if (!(sum % 2))
                count++;
        }
        return count;
    }
};
// @lc code=end
