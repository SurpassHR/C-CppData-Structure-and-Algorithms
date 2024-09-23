#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        auto it = nums.begin() + 1;
        while (it != nums.end()) {
            ans ^= *it;
            it++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 4, 1, 2, 1, 2 };
    Solution sl;
    int ans = sl.singleNumber(nums);
    cout << ans << endl;
    return 0;
}
