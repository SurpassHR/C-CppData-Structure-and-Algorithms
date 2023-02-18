#include "../LeetCode.h"

class Solution {
public:
    int myAtoi(string s) {
        int head = (int)s[0];
        int base = (int)'0';
        int top = (int)'9';
        int space = (int)' ';
        int positive = (int)'+';
        int negative = (int)'-';
        int sign = 1;
        int exp = 1;
        int i;
        long ans = 0;
        bool reading = false;
        bool spacing = false;
        if (head != space && !(head >= base && head <= top) && !(head == negative || head == positive)) {
            cout << "fuck1" << endl;
            return 0;
        }
        for (i = 0; i < s.size(); i++) {
            cout << s[i] << endl;
            if (!reading && (int)s[i] == space) {
                cout << "fuck2" << endl;
                spacing = true;
                continue;
            }
            if (spacing && !((int)s[i] == space) && !((int)s[i] >= base && (int)s[i] <= top) && !((int)s[i] == negative || (int)s[i] == positive)) {
                cout << "fuck spacing" << endl;
                return 0;
            }
            if (reading && !((int)s[i] >= base && (int)s[i] <= top)) {
                cout << "fuck3" << endl;
                break;
            } else if ((int)s[i] == negative || (int)s[i] == positive) {
                cout << "fuck4" << endl;
                reading = true;
                spacing = false;
                sign *= ((int)',' - (int)s[i]);
            } else if ((int)s[i] >= base && (int)s[i] <= top) {
                cout << "fuck5" << endl;
                reading = true;
                spacing = false;
                if (sign * ans > INT32_MAX / 10) return INT32_MAX;
                if (sign * ans < INT32_MIN / 10) return INT32_MIN;
                ans = ans * 10 + ((int)s[i] - base);
                cout << ans << endl;
            }
        }
        if (sign * ans > INT32_MAX) return INT32_MAX;
        if (sign * ans < INT32_MIN) return INT32_MIN;

        return sign * ans;
    }
};

class Solution1 {
public:
    int myAtoi(string s) {
        if (s == "") return 0;
        int space = (int)' ';
        int base = (int)'0';
        int top = (int)'9';
        int positive = (int)'+';
        int negative = (int)'-';
        int sign = 1;
        int cur = 0;
        int i = 0;
        long ans = 0;
        bool spacing = ((int)s[0] == space);
        bool reading = ((int)s[0] >= base && (int)s[0] <= top);
        bool signing = ((int)s[0] == positive || (int)s[0] == negative);
        vector<int> bits;

        if (reading) {
            bits.insert(bits.end(), (int)s[0] - base);
        }
        if (signing) sign *= (int)',' - (int)s[0];


        for (char c : s.substr(1, s.size() - 1)) {
            cur = (int)c;
            if (reading) {
                if (cur >= base && cur <= top) {
                    bits.insert(bits.end(), cur - base);
                } else {
                    break;
                }
            } else if (spacing) {
                if (cur == space) {
                    continue;
                } else if (cur == positive || cur == negative) {
                    spacing = false;
                    signing = true;
                    sign *= (int)',' - cur;
                } else if (cur >= base && cur <= top) {
                    spacing = false;
                    reading = true;
                    bits.insert(bits.end(), cur - base);
                } else {
                    break;
                }
            } else if (signing) {
                if (cur >= base && cur <= top) {
                    signing = false;
                    reading = true;
                    bits.insert(bits.end(), cur - base);
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        while (bits.size() && bits[0] == 0) {
            bits.erase(bits.begin());
        }

        if (bits.size() > 10) {
            return sign > 0 ? INT32_MAX : INT32_MIN;
        }

        for (int it : bits) {
            ans = ans * 10 + it;
        }
        ans *= sign;

        if (ans >= INT32_MAX) return INT32_MAX;
        if (ans <= INT32_MIN) return INT32_MIN;

        return ans;
    }
};

int main(void) {
    // Solution sl;
    // int ans;
    // ans = sl.myAtoi("  -0012a42");
    // cout << ans << endl;
    Solution1 sl1;
    // string s = "  0000000000012345678";
    string s = "2147483647";
    int ans;
    ans = sl1.myAtoi(s);
    cout << ans << endl;

    return 0;
}
