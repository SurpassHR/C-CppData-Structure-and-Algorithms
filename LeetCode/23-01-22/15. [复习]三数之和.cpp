#include "../LeetCode.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        map<int, int> mapPositiveNums, mapNegativeNums, mapZeroNums;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (*it > 0) {
                mapPositiveNums[*it] += 1;
            } else if (*it == 0) {
                mapZeroNums[*it] += 1;
            } else {
                mapNegativeNums[*it] += 1;
            }
        }

        // 测试
        // cout << "test:" << endl;
        // for (map<int, int>::iterator it = mapPositiveNums.begin(); it != mapPositiveNums.end(); it++) {
        //     cout << it->first << ": " << it->second << endl;
        // }
        // for (map<int, int>::iterator it = mapZeroNums.begin(); it != mapZeroNums.end(); it++) {
        //     cout << it->first << ": " << it->second << endl;
        // }
        // for (map<int, int>::iterator it = mapNegativeNums.begin(); it != mapNegativeNums.end(); it++) {
        //     cout << it->first << ": " << it->second << endl;
        // }

        if (mapPositiveNums.size() && mapNegativeNums.size()) {
            for (map<int, int>::iterator itPos = mapPositiveNums.begin(); itPos != mapPositiveNums.end(); itPos++) {
                // 负 + 2 * 正 = 0
                if (itPos->second >= 2 && mapNegativeNums.count(-2 * itPos->first)) {
                    ans.push_back({ -2 * itPos->first, itPos->first, itPos->first });
                }
                // 负 + 0 + 正 = 0
                if (mapZeroNums[0] > 0 && mapNegativeNums.count(-1 * itPos->first)) {
                    ans.push_back({ -1 * itPos->first, 0, itPos->first });
                }
                map<int, int>::iterator itPosInner = itPos;
                itPosInner++;
                for (; itPosInner != mapPositiveNums.end(); itPosInner++) {
                    // 负 + 正 + 正 = 0
                    if (mapNegativeNums.count(-1 * (itPos->first + itPosInner->first))) {
                        ans.push_back({ -1 * (itPos->first + itPosInner->first), itPos->first, itPosInner->first });
                    }
                }

            }

            for (map<int, int>::iterator itNeg = mapNegativeNums.begin(); itNeg != mapNegativeNums.end(); itNeg++) {
                // 2 * 负 + 正 = 0
                if (itNeg->second >= 2 && mapPositiveNums.count(-2 * itNeg->first)) {
                    ans.push_back({ itNeg->first, itNeg->first, -2 * itNeg->first });
                }
                // 负 + 负 + 正 = 0
                map<int, int>::iterator itNegInner = itNeg;
                itNegInner++;
                for (;itNegInner != mapNegativeNums.end(); itNegInner++) {
                    if (mapPositiveNums.count(-1 * (itNeg->first + itNegInner->first))) {
                        ans.push_back({ itNeg->first, itNegInner->first, -1 * (itNeg->first + itNegInner->first) });
                    }
                }
            }
        }
        // 0 + 0 + 0 = 0
        if (mapZeroNums[0] >= 3) {
            ans.push_back({ 0, 0, 0 });
        }

        return ans;
    }
};

int main() {
    Solution sl;
    vector<int> nums = { -1,0,1,2,-1,-4 };
    vector<vector<int>> ans;
    ans = sl.threeSum(nums);

    cout << "ans:" << endl;
    for (auto it1 : ans) {
        for (auto it2 : it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
