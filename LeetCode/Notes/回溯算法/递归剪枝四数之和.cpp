#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int tar, myNumsSize;
    vector<int> myNums, sumNums;
    vector<vector<int>> ans;

    void recursion(int startIndex, long sum) {
        int sumSize = sumNums.size();
        if (sumSize == 4 && sum == tar) {
            ans.push_back(sumNums);
            return;
        }
        for (int i = startIndex; i < myNumsSize; i++) {
            // 去重
            if (i > startIndex && myNums[i] == myNums[i - 1]) {
                continue;
            }
            // 剪枝
            if (4 - sumSize > myNumsSize - i) {
                return;
            }
            if ((long)myNums[i] + (long)sum + (long)(3 - sumSize) * myNums[i + 1] > tar) {
                return;
            }
            if ((long)myNums[i] + (long)sum + (long)(3 - sumSize) * myNums[myNumsSize - 1] < tar) {
                continue;
            }
            sumNums.push_back(myNums[i]);
            recursion(i + 1, sum + myNums[i]);
            sumNums.pop_back();
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        myNums = nums;
        myNumsSize = myNums.size();
        tar = target;
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
