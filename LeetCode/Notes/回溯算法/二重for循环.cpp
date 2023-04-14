#include "../../LeetCode.h"

class Solution {
public:
    string digits;
    vector<string> ans;
    vector<string> mapLetter;
    Solution(string _digits) {
        digits = _digits;
        mapLetter = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    }
    vector<string> doubleFor() {
        int digit2 = digits[0] - '0';
        int digit3 = digits[1] - '0';
        string letter2 = mapLetter[digit2];
        string letter3 = mapLetter[digit3];
        string s = "";
        for (int i = 0; i < letter2.size(); i++) {
            s = "";
            s += letter2[i];
            for (int j = 0; j < letter3.size(); j++) {
                s.push_back(letter3[j]);
                ans.push_back(s);
                s.pop_back();
            }
        }

        return ans;
    }
};

int main() {
    string digits = "23";
    vector<string> ans;
    ans = Solution(digits).doubleFor();
    for (string it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
