/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool CanBePalidromeStr(const string& s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        int odd_count = count_if(count.begin(), count.end(), [](const auto& p) {
            return p.second % 2 == 1;
        });
        return odd_count <= 1;
    }

    string GetPalindromeStr(string inputStr)
    {
        if (!CanBePalidromeStr(inputStr)) {
            return inputStr;
        }

        sort(inputStr.begin(), inputStr.end());
        unordered_map<char, int> count;
        for (char c : inputStr) {
            count[c]++;
        }

        string mid = "";
        string left = "";
        for (auto p : count) {
            if (p.second % 2 == 1) {
                mid = p.first;
            }
            left += string(p.second / 2, p.first);
        }
        sort(left.begin(), left.end());
        string right = left;
        reverse(right.begin(), right.end());

        return mid.empty() ? left + right : left + mid + right;
    }
};


int main()
{
    string s = "abcdd";
    string ret = Solution().GetPalindromeStr(s);
    cout << ret << endl;
    return 0;
}
