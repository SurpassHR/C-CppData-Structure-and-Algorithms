#include "../LeetCode.h"

using namespace std;

class Solution {
public:
    map<char, char> mapDec;
    string decodeMessage(string key, string message) {
        string ans;
        for (int j = 0, i = 'a'; j < key.size() && i <= 'z'; j++) {
            if (key[j] == ' ') continue;
            if (mapDec.count(key[j]) == 0) {
                mapDec.emplace(key[j], i);
                i++;
            }
        }

        for (char it : message) {
            if (it == ' ') {
                ans += it;
                continue;
            }
            ans += mapDec[it];
        }

        return ans;
    }
};

int main() {
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    Solution sl;
    string ans = sl.decodeMessage(key, message);
    cout << ans << endl;

    return 0;
}
