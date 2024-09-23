// 219. Contains Duplicate II

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int right = 0;
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.count(nums[i])) {
                return true;
            }
            set.insert(nums[i]);
            if (set.size() > k) {
                set.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main()
{
    Solution sl;

    vector<int> nums = { 1,2,3,1,2,3 };
    int k = 2;
    bool res = sl.containsNearbyDuplicate(nums, k);
    cout << "res: " << res << endl;

    return 0;
}