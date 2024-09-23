#include "../LeetCode.h"
using namespace std;

class Solution {
public:
    //     int removeDuplicates(vector<int>& nums) {
    //         vector<int>::iterator it1 = nums.begin();
    //         vector<int>::iterator it2 = it1;
    //         it2++;
    //         while (it1 != nums.end() && it2 != nums.end()) {
    //             if (*it2 == *it1) {
    //                 nums.erase(it2);
    //             } else {
    //                 it1++;
    //                 it2++;
    //             }
    //         }
    //
    //         // 测试
    //         cout << "test:" << endl;
    //         for (auto it : nums) {
    //             cout << it << " ";
    //         }
    //         cout << endl;
    //
    //         return nums.size();
    //     }

    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int i = 0, j = i + 1, size = nums.size();
        while (i < size && j < size) {
            if (nums[i] != nums[j]) {
                nums[i + 1] = nums[j];
                i++;
            }
            j++;
        }

        return i;
    }
};

int main() {
    Solution sl;
    int ans;
    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
    ans = sl.removeDuplicates(nums);
    cout << ans << endl;

    return 0;
}
