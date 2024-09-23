#include "../LeetCode.h"

/* 超出时间限制 */
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if (isPalindrome(s)) return s;
//
//         int begin = 0, length = 0;
//         string p;  // p for palindrome
//         int i, j;
//         for (i = 0; i < s.size(); i++) {
//             for (j = i; j < s.size(); j++) {
//                 p.append(1, s[j]);
//                 if (isPalindrome(p) && p.size() > length) {
//                     cout << "p = " << p << endl;
//                     cout << "i = " << i << ", " << "j = " << j << endl;
//                     length = p.size();
//                     begin = i;
//                 }
//             }
//             p = "";
//         }
//
//         // cout << "begin = " << begin << ", " << "length = " << length << endl;
//         return s.substr(begin, length);
//     }
//
//     bool isPalindrome(string p) {
//         int i;
//         for (i = 0; i < p.size() / 2; i++) {
//             // cout << "p[" << i << "] = " << p[i] << ", " << "p[" << p.size() - i - 1 << "] = " << p[p.size() - i - 1] << endl;
//             if (p[i] != p[p.size() - i - 1]) return false;
//         }
//
//         return true;
//     }
// };

/* 从中间向两边扩散，分奇偶 */
class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, begin = 0, length = 0;
        for (i = 0; i < s.size(); i++) {
            // 奇数
            cout << "\nodd: " << endl;
            for (j = 0; i - j >= 0 && i + j < s.size(); j++) {
                cout << "i = " << i << ", j = " << j << endl;
                cout << "s[" << i << " - " << j << "] = " << s[i - j] << ", " << "s[" << i << " + " << j << "] = " << s[i + j] << endl;
                if (s[i - j] != s[i + j]) break;
                if (2 * j + 1 > length) {
                    cout << "new length" << endl;
                    begin = i - j;
                    length = 2 * j + 1;
                    cout << "length = " << length << endl;
                }
            }
            // 偶数
            cout << "\neven: " << endl;
            for (j = 0; i - j >= 0 && i + 1 + j < s.size(); j++) {
                if (s[i] == s[i + 1]) {
                    cout << "s[" << i << "] = " << s[i] << ", " << "s[" << i + 1 << "] = " << s[i + 1] << endl;
                    cout << "i = " << i << ", j = " << j << endl;
                    cout << "s[" << i << " - " << j << "] = " << s[i - j] << ", " << "s[" << i << " + " << 1 << " + " << j << "] = " << s[i + j + 1] << endl;
                    if (s[i - j] != s[i + 1 + j]) break;
                    if (2 * j + 2 > length) {
                        cout << "new length" << endl;
                        begin = i - j;
                        length = 2 * j + 2;
                        cout << "length = " << length << endl;
                    }
                }
            }
        }

        return s.substr(begin, length);
    }
};

int main(void) {
    string s = "cbbd";
    Solution sl;
    cout << sl.longestPalindrome(s) << endl;
    // cout << max(1, 2) << endl;
    // cout << sl.isPalindrome("babad") << endl;

    return 0;
}
