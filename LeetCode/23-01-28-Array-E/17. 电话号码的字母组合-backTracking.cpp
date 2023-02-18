#include "../LeetCode.h"

class Solution {
public:
    string s;
    vector<string> ans;
    map<int, string> mapDigitChar;
    // 回溯算法(backtracking)
    vector<string> letterCombinations(string digits) {
        int index = 0;
        mapDigitChar.emplace(2, "abc");
        mapDigitChar.emplace(3, "def");
        mapDigitChar.emplace(4, "ghi");
        mapDigitChar.emplace(5, "jkl");
        mapDigitChar.emplace(6, "mno");
        mapDigitChar.emplace(7, "pqrs");
        mapDigitChar.emplace(8, "tuv");
        mapDigitChar.emplace(9, "wxyz");

        backTracking(digits, index);

        return ans;
    }

    void backTracking(string digits, int index) {
        if (index == digits.size()) {
            ans.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letter = mapDigitChar[digit];
        for (int i = 0; i < letter.size(); i++) {
            s.push_back(letter[i]);
            backTracking(digits, index + 1);
            s.pop_back();
        }
    }


};

int main() {
    Solution sl;
    vector<string> ans;
    string digits = "23";
    ans = sl.letterCombinations(digits);
    for (string it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
