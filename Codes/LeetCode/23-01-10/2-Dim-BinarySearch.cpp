#include "../LeetCode.h"

// 折半删除
class Solution {
public:
    int binarySearch(vector<int> v1, vector<int> v2) {
        int total = v1.size() + v2.size();
        // v1
        int left1, right1;
        left1 = 0;
        right1 = v1.size() - 1;
        // v2
        int left2, right2;
        left2 = 0;
        right2 = v2.size() - 1;
        // mid
        int spLine1, spLine2;
        spLine1 = (left1 + right1) / 2;
        spLine2 = (left2 + right2) / 2;
        // possible midian
        int prev1, next1, prev2, next2;
        prev1 = v1[spLine1 - 1];
        next1 = v1[spLine1];
        prev2 = v2[spLine2 - 1];
        next2 = v2[spLine2];
        // left num, right num
        int leftTotal, rightTotal;
        leftTotal = total / 2;
        rightTotal = total - leftTotal;

        while (max(prev1, prev2) > min(next1, next2) && spLine1 >= 0 && spLine1 <= v1.size() - 1 && spLine2 >= 0 && spLine2 <= v2.size() - 1) {
            if (prev1 > prev2) {
                right1 = spLine1;
                spLine1 =
            }
        }
    }
};


int main(void) {
    Solution sl;


    return 0;
}
