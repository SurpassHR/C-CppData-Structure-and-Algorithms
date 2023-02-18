#include "../LeetCode.h"

using namespace std;

class Solution {
private:
    void rec(string s) {
        if (s.size() > 2 * myN) {
            return;
        }
    }

public:
    int myN;
    vector<string> generateParenthesis(int n) {
        myN = n;
    }
};

int main() {
    Solution sl;
    int n;
    vector<string> ans;
    ans = sl.generateParenthesis(n);
    for (string it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
