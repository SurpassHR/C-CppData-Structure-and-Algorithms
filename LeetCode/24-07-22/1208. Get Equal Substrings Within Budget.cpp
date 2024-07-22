#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left, right;
        left = right = 0;
        int cost = 0;
        int res = 0;
        while (right < s.size()) {
            cost += std::abs(s[right] - t[right]);
            right++;
            while (cost > maxCost) {
                cost -= std::abs(s[left] - t[left]);
                left++;
            }
            res = std::max(res, right - left);
        }
        return res;
    }
};

int main()
{
    Solution solu;
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    int maxSubs = solu.equalSubstring(s, t, 3);
    cout << "maxSubs: " << maxSubs << endl;
    return 0;
}