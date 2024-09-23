#include "../LeetCode.h"
#include <queue>
using namespace std;

class Solution {
private:
    void rec(int l_num, int r_num, string s) {
        int len = s.size();
        if (l_num == 0 && r_num != 0) {
            // for (int i = 0; i < len; i++) s += ')';
            s.insert(len, r_num, ')');
            parentheses.push_back(s);
            s = s.substr(0, len - r_num);
            return;
        } else if (l_num > r_num) {
            return;
        } else {
            rec(l_num - 1, r_num, s + '(');
            rec(l_num, r_num - 1, s + ')');
        }
    }
public:
    vector<string> parentheses;
    vector<string> generateParenthesis(int n) {
        rec(n, n, "");
        return parentheses;
    }
};

int main() {
    Solution sl;
    int n = 3;
    vector<string> ans;
    ans = sl.generateParenthesis(n);
    for (string it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
