#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string digits;
    vector<string> mapLetter;
    vector<string> ans;
    Solution(string _digits) {
        mapLetter = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        digits = _digits;
    }

    void recFor(string s, int index) {
        if (index >= digits.size()) {
            ans.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letter = mapLetter[digit];
        for (int i = 0; i < letter.size(); i++) {
            s.push_back(letter[i]);
            recFor(s, index + 1);
            s.pop_back();
        }
    }
};

int main() {
    Solution sl("23");
    sl.recFor("", 0);
    for (string it : sl.ans) {
        cout << it << " ";
    }
    cout << endl;
}
