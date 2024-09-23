#include "../LeetCode.h"
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        string ans;
        char c = strs[0][0];
        int minLen = 200;
        for (int i = 0; i < strs.size(); i++) {
            minLen = strs[i].size() < minLen ? strs[i].size() : minLen;
        }
        for (int i = 0; i < minLen; i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (c != strs[j][i]) {
                    return ans;
                }
            }
            c = strs[0][i + 1];
            ans += strs[0][i];
        }

        return ans;
    }
};


int main() {
    vector<string> strs = { "flower","flow","flight" };
    Solution sl;
    string ans;
    ans = sl.longestCommonPrefix(strs);
    cout << ans << endl;

    return 0;
}
