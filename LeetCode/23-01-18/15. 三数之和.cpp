#include "../LeetCode.h"

class Solution {
public:
    //     vector<vector<int>> threeSum(vector<int>& nums) {
    //         vector<vector<int>> ans;
    //         int i, j, k;
    //         for (i = 0; i < nums.size() - 2; i++) {
    //             for (j = i + 1; j < nums.size() - 1; j++) {
    //                 for (k = j + 1; k < nums.size(); k++) {
    //                     vector<int> tmp;
    //                     if (nums[i] + nums[j] + nums[k] == 0) {
    //                         tmp.insert(tmp.end(), nums[i]);
    //                         tmp.insert(tmp.end(), nums[j]);
    //                         tmp.insert(tmp.end(), nums[k]);
    //
    //                         sort(tmp.begin(), tmp.end());
    //                         if (ans.size()) {
    //                             bool notInclude = true;
    //                             for (int l = 0; l < ans.size(); l++) {
    //                                 if (ans[l][0] == tmp[0] && ans[l][1] == tmp[1] && ans[l][2] == tmp[2]) {
    //                                     notInclude = false;
    //                                 }
    //                             }
    //                             if (notInclude) {
    //                                 ans.insert(ans.end(), tmp);
    //                             }
    //                         } else {
    //                             ans.insert(ans.end(), tmp);
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //
    //         return ans;
    //     }

    //     vector<vector<int>> threeSum(vector<int>& nums) {
    //         sort(nums.begin(), nums.end());
    //         vector<vector<int>> ans;
    //         // <value, num>
    //         unordered_map<int, int> positives, negatives;
    //         int zeros = 0;
    //         for (int it : nums) {
    //             if (it == 0) {
    //                 zeros += 1;
    //             } else if (it > 0) {
    //                 positives[it] += 1;
    //             } else {
    //                 negatives[it] += 1;
    //             }
    //         }
    //
    //         // 调试
    //         cout << "positives:" << endl;
    //         cout << "size:" << positives.size() << endl;
    //         for (auto posIter : positives) cout << "value: " << posIter.first << ", " << "num: " << posIter.second << endl;
    //         cout << "negatives:" << endl;
    //         cout << "size:" << negatives.size() << endl;
    //         for (auto negIter : negatives) cout << "value: " << negIter.first << ", " << "num: " << negIter.second << endl;
    //         cout << "zeros:" << zeros << "\n" << endl;
    //
    //         if (zeros >= 3) {
    //             ans.insert(ans.end(), { 0, 0, 0 });
    //         }
    //
    //
    //         if (positives.size() && negatives.size()) {
    //             for (auto posIter1 = positives.begin(); posIter1 != positives.end(); posIter1++) {
    //
    //                 int count = posIter1->second;
    //                 cout << "count = " << count << endl;
    //                 // 2 * 正 + 负 = 0
    //                 if (count >= 2 && negatives.find(-2 * posIter1->first) != negatives.end()) {
    //                     cout << "fuck1" << endl;
    //                     ans.insert(ans.end(), { posIter1->first, posIter1->first, -2 * posIter1->first });
    //                 }
    //                 // 正 + 负 + 0 = 0
    //                 if (negatives.find(-posIter1->first) != negatives.end() && zeros) {
    //                     cout << "fuck2" << endl;
    //                     ans.insert(ans.end(), { posIter1->first, -posIter1->first, 0 });
    //                 }
    //                 // 正 + 正 + 负 = 0
    //                 for (auto posIter2 = posIter1; posIter2 != positives.end(); posIter2++) {
    //                     if (posIter2->first >= posIter1->first) continue;
    //                     if (negatives.find(-1 * (posIter1->first + posIter2->first)) != negatives.end()) {
    //                         cout << "fuck3" << endl;
    //                         ans.insert(ans.end(), { -1 * (posIter1->first + posIter2->first), posIter1->first, posIter2->first });
    //                     }
    //                 }
    //             }
    //
    //             for (auto negIter1 = negatives.begin(); negIter1 != negatives.end(); negIter1++) {
    //                 // cout << "negIter1 = " << negIter1->first << endl;
    //                 int count = negIter1->second;
    //                 cout << "count = " << count << endl;
    //
    //                 // 2 * 负 + 正 = 0
    //                 if (count >= 2 && positives.find(-2 * negIter1->first) != positives.end()) {
    //                     cout << "fuck4" << endl;
    //                     ans.insert(ans.end(), { negIter1->first, negIter1->first, -2 * negIter1->first });
    //                 }
    //                 //负 + 负 + 正 = 0
    //                 for (auto negIter2 = negIter1; negIter2 != negatives.end(); negIter2++) {
    //                     cout << "negIter1 = " << negIter1->first << ", " << "negIter2 = " << negIter2->first << endl;
    //                     if (negIter2->first >= negIter1->first) continue;
    //                     if (positives.find(-1 * (negIter1->first + negIter2->first)) != positives.end()) {
    //                         cout << "fuck5" << endl;
    //                         ans.insert(ans.end(), { -1 * (negIter1->first + negIter2->first), negIter1->first, negIter2->first });
    //                     }
    //                 }
    //             }
    //
    //         }
    //
    //         return ans;
    //     }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;

        map<int, int> mapPositiveNums;
        map<int, int> mapZeroNums;
        map<int, int> mapNegativeNums;
        for (auto v : nums) {
            if (v > 0) {
                mapPositiveNums[v] = count(nums.begin(), nums.end(), v);
                continue;
            }
            if (v < 0) {
                mapNegativeNums[v] = count(nums.begin(), nums.end(), v);
                continue;
            }
            if (v == 0) {
                mapZeroNums[v] = count(nums.begin(), nums.end(), v);
                continue;
            }
        }
        // 调试
        cout << "mapPositiveNums:" << endl;
        for (auto it : mapPositiveNums) cout << "value:" << it.first << ", " << "num:" << it.second << endl;
        cout << endl;
        cout << "mapNegativeNums:" << endl;
        for (auto it : mapNegativeNums) cout << "value:" << it.first << ", " << "num:" << it.second << endl;
        cout << endl;

        // 剪枝: 0 + 0 + 0 = 0
        if (mapZeroNums.size() > 0 && mapZeroNums[0] > 2) {
            vector<int> tmpV{ 0, 0, 0 };
            result.push_back(tmpV);
        }
        for (auto iterP = mapPositiveNums.begin(); iterP != mapPositiveNums.end(); iterP++) {
            // 剪枝: 负 + 2 * 正 = 0
            if (iterP->second > 1) {
                if (1 == mapNegativeNums.count(iterP->first * (-2))) {
                    vector<int> tmpV{ iterP->first * (-2), iterP->first, iterP->first };
                    result.push_back(tmpV);
                }
            }
            // 剪枝: 正 + 0 + 负 = 0
            if (mapZeroNums.size() > 0 && 1 == mapNegativeNums.count(iterP->first * (-1))) {
                vector<int> tmpV{ iterP->first * (-1), 0, iterP->first };
                result.push_back(tmpV);
            }
            auto iterP2 = iterP;
            iterP2++;
            // 负 + 正 + 正 = 0
            while (iterP2 != mapPositiveNums.end()) {
                if (1 == mapNegativeNums.count((iterP->first + iterP2->first) * (-1))) {
                    vector<int> tmpV{ (iterP->first + iterP2->first) * (-1), iterP->first, iterP2->first };
                    result.push_back(tmpV);
                }
                iterP2++;
            }
        }

        for (auto iterN = mapNegativeNums.begin(); iterN != mapNegativeNums.end(); iterN++) {
            if (iterN->second > 1) {
                // 剪枝: 2 * 负 + 正 = 0
                if (1 == mapPositiveNums.count(iterN->first * (-2))) {
                    vector<int> tmpV{ iterN->first, iterN->first, iterN->first * (-2) };
                    result.push_back(tmpV);
                }
            }
            auto iterN2 = iterN;
            iterN2++;
            while (iterN2 != mapNegativeNums.end()) {
                // 负 + 负 + 正 = 0
                if (1 == mapPositiveNums.count((iterN->first + iterN2->first) * (-1))) {
                    vector<int> tmpV{ iterN->first, iterN2->first, (iterN->first + iterN2->first) * (-1) };
                    result.push_back(tmpV);
                }
                iterN2++;
            }
        }

        return result;
    }

    // 二分法查找
    bool inc(vector<int> v, int target) {
        // sort(v.begin(), v.end());
        int left, right, midian;

        left = 0; right = v.size() - 1;
        midian = (left + right) / 2;

        while (left <= right) {
            if (v[midian] == target) {
                break;
            } else if (v[midian] > target) {
                right = midian - 1;
                midian = (left + right) / 2;
            } else if (v[midian] < target) {
                left = midian + 1;
                midian = (left + right) / 2;
            }
        }

        if (left > right) return false;
        return true;
    }
};

int main(void) {
    vector<int> nums;
    // nums = { 3,0,-2,-1,1,2 };
    nums = { -1,0,1,2,-1,-4 };
    vector<vector<int>> ans;
    Solution sl;
    ans = sl.threeSum(nums);
    for (vector<int> it1 : ans) {
        for (int it2 : it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
