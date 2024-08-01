// 1. Two Sum - hashmap

#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::multimap<int, int> numsMap;
        for (int i = 0; i < nums.size(); ++i) {
            numsMap.insert({ nums[i], i });
        }
        for (auto iter = numsMap.begin(); iter != numsMap.end(); ++iter) {
            int num2 = target - iter->first;
            auto res2 = numsMap.equal_range(num2);
            for (auto p = res2.first; p != res2.second; ++p) {
                if (p != iter) {
                    return { p->second, iter->second };
                }
            }
        }
        return {};
    }
};

void testMap()
{
    std::map<int, int> tMap = {
        { 1, 2 },
        { 2, 3 },
        { 1, 3 },
        { 3, 3 },
    };
    auto res = tMap.equal_range(1);
    for (auto iter = res.first; iter != res.second; ++iter) {
        cout << iter->first << "\t" << iter->second << endl;
    }

    std::cout << std::endl;

    std::multimap<int, int> ttMap = {
        { 1, 2 },
        { 2, 3 },
        { 1, 3 },
        { 3, 3 },
    };
    res = ttMap.equal_range(1);
    for (auto iter = res.first; iter != res.second; ++iter) {
        cout << iter->first << "\t" << iter->second << endl;
    }
}

int main()
{
    Solution sl;
    std::vector<int> nums = { 3, 3 };
    std::vector<int> res = sl.twoSum(nums, 6);
    for (auto iter : res) {
        std::cout << iter << "\t";
    }
    std::cout << "\n";

    // testMap();

    return 0;
}