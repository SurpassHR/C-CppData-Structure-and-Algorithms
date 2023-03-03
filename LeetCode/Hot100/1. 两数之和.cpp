#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> idxs;
        for (int i = 0; i < n; i++) idxs.push_back(i);
        sort(idxs.begin(), idxs.end(), [nums, idxs](int i, int j) -> bool {
            return nums[idxs[i]] < nums[idxs[j]];
            });
        int left, right;
        left = 0, right = n - 1;
        vector<int> ans;
        while (left != right) {
            if (nums[idxs[left]] + nums[idxs[right]] == target) {
                ans.push_back(idxs[left]);
                ans.push_back(idxs[right]);
                break;
            } else if (nums[idxs[left]] + nums[idxs[right]] > target) {
                right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
