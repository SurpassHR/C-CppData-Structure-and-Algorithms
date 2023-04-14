#include "../LeetCode.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        stack<char> st;
        for (; i < s.size(); i++) {
            if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && !st.empty() && s[i] != st.top() && abs(s[i] - st.top()) <= 2) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        if (st.size() == 0) return true;
        return false;
    }
};

int main() {
    Solution sl;
    string s = "({{{{}}}))";
    bool ans;
    ans = sl.isValid(s);
    cout << ans << endl;

    return 0;
}
