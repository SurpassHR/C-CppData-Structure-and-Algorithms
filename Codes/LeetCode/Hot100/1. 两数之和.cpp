#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> idxs;
//         for (int i = 0; i < n; i++) idxs.push_back(i);
//         sort(idxs.begin(), idxs.end(), [nums, idxs](int i, int j) -> bool {
//             return nums[idxs[i]] < nums[idxs[j]];
//             });
//         int left, right;
//         left = 0, right = n - 1;
//         vector<int> ans;
//         while (left != right) {
//             if (nums[idxs[left]] + nums[idxs[right]] == target) {
//                 ans.push_back(idxs[left]);
//                 ans.push_back(idxs[right]);
//                 break;
//             } else if (nums[idxs[left]] + nums[idxs[right]] > target) {
//                 right--;
//             } else {
//                 left++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ret;
        multimap<int, int> mmap;
        for (int i = 0; i < size; i++) {
            // 当前要查找的第二个元素
            int toFind = target - nums[i];
            auto itToFind = mmap.equal_range(toFind);
            auto left = itToFind.first;
            auto right = itToFind.second;
            if (left != right && left->first == toFind && left->second != i) {
                ret.push_back(left->second);
                ret.push_back(i);
                return ret;
            }
            mmap.emplace(nums[i], i);
        }
        return {};
    }
};

int main() {
    vector<int> nums = { 1,1,1,1,1,4,1,1,1,1,1,7,1,1,1,1,1 };
    int num = 11;
    vector<int> ret = Solution().twoSum(nums, num);
    cout << ret[0] << ", " << ret[1] << endl;
    return 0;
}
