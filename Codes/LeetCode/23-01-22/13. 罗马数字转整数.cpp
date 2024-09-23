#include "../LeetCode.h"

class Solution {
public:
    //     int romanToInt(string s) {
    //         int ans = 0;
    //         map<string, int> romansMap;
    //         romansMap.emplace("IV", 4);
    //         romansMap.emplace("IX", 9);
    //         romansMap.emplace("XL", 40);
    //         romansMap.emplace("XC", 90);
    //         romansMap.emplace("CD", 400);
    //         romansMap.emplace("CM", 900);
    //         romansMap.emplace("I", 1);
    //         romansMap.emplace("V", 5);
    //         romansMap.emplace("X", 10);
    //         romansMap.emplace("L", 50);
    //         romansMap.emplace("C", 100);
    //         romansMap.emplace("D", 500);
    //         romansMap.emplace("M", 1000);
    //         while (s.size()) {
    //             for (map<string, int>::iterator it = romansMap.begin(); it != romansMap.end(); it++) {
    //                 if (it->first.size() == 2 && s.find(it->first) < s.size()) {
    //                     ans += it->second;
    //                     s.erase(s.find(it->first), 2);
    //                 }
    //             }
    //             for (map<string, int>::iterator it = romansMap.begin(); it != romansMap.end(); it++) {
    //                 if (it->first.size() == 1 && s.find(it->first) < s.size()) {
    //                     ans += it->second;
    //                     s.erase(s.find(it->first), 1);
    //                 }
    //             }
    //         }
    //
    //         return ans;
    //     }

    map<string, int> mapRomans;
    int romanToInt(string s) {
        int ans = 0, i, j;
        mapRomans.emplace("IV", 4);
        mapRomans.emplace("IX", 9);
        mapRomans.emplace("XL", 40);
        mapRomans.emplace("XC", 90);
        mapRomans.emplace("CD", 400);
        mapRomans.emplace("CM", 900);
        mapRomans.emplace("I", 1);
        mapRomans.emplace("V", 5);
        mapRomans.emplace("X", 10);
        mapRomans.emplace("L", 50);
        mapRomans.emplace("C", 100);
        mapRomans.emplace("D", 500);
        mapRomans.emplace("M", 1000);
        for (i = 0, j = i + 1; j < s.size(); i++, j++) {
            string t;
            t += s[i];
            t += s[j];
            ans += mapRomans.count(t) ? -mapRomans[string(1, s[i])] : mapRomans[string(1, s[i])];
        }
        ans += mapRomans[string(1, s[i])];

        return ans;
    }
};

int main(void) {
    Solution sl;
    string s;
    int ans;
    s = "MCMXCIV";
    ans = sl.romanToInt(s);
    cout << ans << endl;

    return 0;
}
