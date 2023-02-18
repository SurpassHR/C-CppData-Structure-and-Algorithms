#include "../LeetCode.h"

class Solution {
   public:
    // 滑动窗口
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        // cout << size << endl;
        if (size == 0) return 0;
        int max_len = 1;
        int i, j;
        for (i = 0, j = i + 1; i < size - 1, j < size;) {
            // while (s.substr(i, j - i).find(s[j]) == string().npos && j < size) {
            //     j++;
            // }
            // i++;
            cout << s.substr(i, j - i + 1) << endl;
            if (s.substr(i, j - i).find(s[j]) == string().npos)
                j++;
            else
                i++;
            max_len = max(j - i + 1, max_len);
        }

        return max_len;
    }

    //     // 滑动窗口优化，无序集合
    //     int lengthOfLongestSubstring(string s) {
    //         int size = s.size();
    //         if (size == 0) return 0;
    //         unordered_set<char> set;
    //         int max_len = 1;
    //         int i, j;
    //         set.insert(s[0]);
    //         for (i = 0, j = i + 1; i < size - 1, j < size;) {
    //             if (set.find(s[j]) == set.end()) {
    //                 set.insert(s[j]);
    //                 j++;
    //             } else {
    //                 set.erase(s[i]);
    //                 i++;
    //             }
    //             // for (auto it = set.begin(); it != set.end(); it++) {
    //             //     cout << *it << " ";
    //             // }
    //             // cout << endl;
    //             max_len = max(max_len, (int)set.size());
    //         }
    //
    //         return max_len;
    //     }
};

int main(void) {
    // string s = "abcabcbb";
    string s = "au";

    int size = Solution().lengthOfLongestSubstring(s);
    cout << size << endl;
    // 无序集合 unordered_set
    //     unordered_set<char> set;
    //     set.insert('a');
    //     set.insert('s');
    //     set.insert('d');
    //
    //     if (set.find('a') != set.end()) {
    //         cout << "not found a" << endl;
    //     } else {
    //         cout << "find a" << endl;
    //     }

    return 0;
}
