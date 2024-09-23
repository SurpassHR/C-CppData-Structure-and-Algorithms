#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i; j < nums.size(); j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};
        if (nums.size() == 2) return {0, 1};
        // <value, index>
        vector<int> ans;
        multimap<int, int> mmapNums;

        for (int i = 0; i < nums.size(); i++) {
            auto itFind = mmapNums.equal_range(target - nums[i]);
            auto upper = itFind.first;
            while (upper != itFind.second) {
                // 不允许输出两个一样的下标
                if (upper->second != i) {
                    ans.push_back(i);
                    ans.push_back(upper->second);
                    return ans;
                }
                upper++;
            }
            mmapNums.emplace(nums[i], i);
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = sl.twoSum(nums, target);
    if (ans.size() == 2) {
        cout << ans[0] << ", " << ans[1] << endl;
    }
    return 0;
}