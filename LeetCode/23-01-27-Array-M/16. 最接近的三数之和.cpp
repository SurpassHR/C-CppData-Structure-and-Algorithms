#include "../LeetCode.h"
using namespace std;

class Solution {
public:
    // 双指针法
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestNum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int threeSum = nums[i] + nums[j] + nums[k];
                if (abs(threeSum - target) < abs(closestNum - target)) {
                    closestNum = threeSum;
                }
                if (threeSum > target) {
                    k -= 1;
                } else if (threeSum < target) {
                    j += 1;
                } else {
                    break;
                }
            }
        }

        return closestNum;
    }
};

int main() {
    Solution sl;
    int ans, target = 1;
    vector<int> nums = { -1,2,1,-4 };
    ans = sl.threeSumClosest(nums, target);
    cout << "ans:" << endl;
    cout << ans << endl;

    return 0;
}
