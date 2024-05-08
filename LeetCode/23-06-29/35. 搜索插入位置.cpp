#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int cur = (left + right) / 2;

        while (nums[cur] != target && left < right) {
            int curNum = nums[cur];
            if (curNum >= target) {
                right = cur;
            } else {
                left = cur;
            }
            cur = (left + right) / 2;
        }

        if (left > right) { // 未找到目标值
            for (int i = 0; i < nums.size(); i++) {
                if (target < nums[i]) {
                    return i;
                }
            }
        } else { // 找到目标值
            return cur;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = { 1,3,5,6 };
    int target = 7;
    cout << Solution().searchInsert(nums, target) << endl;

    return 0;
}