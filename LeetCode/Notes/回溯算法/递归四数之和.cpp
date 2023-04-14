#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int tar;
    vector<int> myNums, sumNums;
    vector<vector<int>> ans;

    void recursion(int startIndex, int sum) {
        if (sumNums.size() == 4 && sum == tar) {
            ans.push_back(sumNums);
            return;
        }
        for (int i = startIndex; i < myNums.size(); i++) {
            sumNums.push_back(myNums[i]);
            recursion(i + 1, sum + myNums[i]);
            sumNums.pop_back();
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        tar = target;
        myNums = nums;
        recursion(0, 0);

        return ans;
    }
};

int main() {
    Solution sl;
    vector<vector<int>> ans;
    int target = 0;
    vector<int> nums = { -1, 1, 0, 0, -2, 2 };
    ans = sl.fourSum(nums, target);
    for (vector<int> it : ans) {
        for (int it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
