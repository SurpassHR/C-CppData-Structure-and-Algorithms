#include "../LeetCode.h"

class Solution {
private:
    int tar, numsSize;
    vector<int> myNums, sumNums;
    vector<vector<int>> ans;
    void recFor(int startIndex, int sum) {
        // 递归终止条件
        if (sumNums.size() >= 4 && sum == tar) {
            ans.push_back(sumNums);
            return;
        }
        for (int i = startIndex; i < numsSize; i++) {
            if (numsSize - i < 4 - sumNums.size()) { // 剪枝：剩余元素凑不够4个
                return;
            }
            if (sum + myNums[i] + (long)(3 - sumNums.size()) * myNums[i + 1] > tar) { // 剪枝：已知和使用后续最小值补充空位已经大于target
                return;
            }
            if (sum + myNums[i] + (long)(3 - sumNums.size()) * myNums[numsSize - 1] < tar) { // 剪枝：已知和使用后续最大值补充空位仍然小于target
                continue;
            }
            if (i > startIndex && myNums[i] == myNums[i - 1]) { // 去重：当前元素与上一个元素相同
                continue;
            }
            sumNums.push_back(myNums[i]);
            recFor(i + 1, (long)sum + myNums[i]);
            sumNums.pop_back();
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        myNums = nums;
        numsSize = nums.size();
        tar = target;
        recFor(0, 0);
        // 集合去重
        // set<vector<int>> s(nums.begin(), nums.end());
        // nums.assign(s.begin(), s.end());

        return ans;
    }
};

int main() {
    Solution sl;
    int target = 0;
    vector<int> nums = { 1, 0, -1, 0, -2, 2 };
    vector<vector<int>> ans;
    ans = sl.fourSum(nums, target);
    for (vector<int> it : ans) {
        for (int it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
