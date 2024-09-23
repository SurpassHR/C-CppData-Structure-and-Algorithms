#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 从后向前找到第一对后项大于前项的两数
        int i = nums.size() - 1;
        for (; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                break;
            }
        }
        // 当前序列已经是最大字典序，则变为最小字典序
        if (i == 0) {
            reverse(nums.begin(), nums.end());
        } else if (i == nums.size() - 1) {
            swap(nums[nums.size() - 1], nums[nums.size() - 2]);
        } else {
            // 找到子序列中比前面数大的最小数
            int j = nums.size() - 1;
            for (; j >= i; j--) {
                if (nums[j] > nums[i - 1]) {
                    swap(nums[j], nums[i - 1]);
                    break;
                }
            }
            // 将子序列按升序排列
            sort(nums.begin() + i, nums.end());
        }
    }
};

int main() {
    vector<int> nums;
    int num = 0;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }
    Solution().nextPermutation(nums);
    for (int it : nums) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
