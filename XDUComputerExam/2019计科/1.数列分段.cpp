#include <iostream>
#include <vector>

class Solution {
public:
    int sequenceSegs(std::vector<int> nums) {
        int i = 0, j = 1;
        for (; i < nums.size(), j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main() {
    std::vector<int> nums = { 8,8,8,0,12,12,8,0 };
    Solution sl;
    int ans;
    ans = sl.sequenceSegs(nums);
    std::cout << ans << std::endl;

    return 0;
}
