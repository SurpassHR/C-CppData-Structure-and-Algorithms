#include "../LeetCode.h"

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> bits;
        int i;
        if (x < 0) return false;
        while (x != 0) {
            bits.insert(bits.begin(), x % 10);
            x /= 10;
        }

        for (i = 0; i < bits.size(); i++) {
            if (bits[i] != bits[bits.size() - 1 - i]) return false;
        }

        return true;
    }
};

int main(void) {
    Solution sl;
    int x = 12121;
    bool ans;
    ans = sl.isPalindrome(x);
    cout << ans << endl;
    return 0;
}
