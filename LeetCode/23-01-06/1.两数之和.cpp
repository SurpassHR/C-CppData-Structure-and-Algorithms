#include "../LeetCode.h"

class Solution {
public:
    // 暴力法: 二重循环遍历求和是否等于target
    //     vector<int> twoSum(vector<int>& nums, int target) {
    //         int i, j;
    //         int size = nums.size();
    //         for (i = 0; i < size - 1; i++) {
    //             for (j = i + 1; j < size; j++) {
    //                 if (target == nums[i] + nums[j]) return { i, j };
    //             }
    //         }
    //
    //         return { i, j };
    //     }

    // 哈希法: 将第二次循环的时间复杂度降至O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2) return nums;
        // <value, index>
        vector<int> ans;
        multimap<int, int> mmapNums;
        // for (int i = 0; i < nums.size(); i++) {
        //     mmapNums.emplace(nums[i], i);
        // }

        for (int i = 0; i < nums.size(); i++) {
            auto itFind = mmapNums.equal_range(target - nums[i]);
            auto upper = itFind.first;
            while (upper != itFind.second) {
                if (upper->second != i) {
                    ans.insert(ans.end(), i);
                    ans.insert(ans.end(), upper->second);
                    return ans;
                }
                upper++;
            }
            mmapNums.emplace(nums[i], i);
        }

        return ans;
    }
};

int main() {
    vector<int> ans;
    vector<int> nums = { 0,4,3,0 };
    int target = 0;
    Solution sl;
    ans = sl.twoSum(nums, target);
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
