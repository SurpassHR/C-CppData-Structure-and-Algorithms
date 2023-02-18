#include "../LeetCode.h"

class Solution {
public:
    //     string intToRoman(int num) {
    //         string ans;
    //         map<int, string> mapRomans;
    //         mapRomans.emplace(1, "I");
    //         mapRomans.emplace(2, "II");
    //         mapRomans.emplace(3, "III");
    //         mapRomans.emplace(4, "IV");
    //         mapRomans.emplace(5, "V");
    //         mapRomans.emplace(6, "VI");
    //         mapRomans.emplace(7, "VII");
    //         mapRomans.emplace(8, "VIII");
    //         mapRomans.emplace(9, "IX");
    //         mapRomans.emplace(10, "X");
    //         mapRomans.emplace(20, "XX");
    //         mapRomans.emplace(30, "XXX");
    //         mapRomans.emplace(40, "XL");
    //         mapRomans.emplace(50, "L");
    //         mapRomans.emplace(60, "LX");
    //         mapRomans.emplace(70, "LXX");
    //         mapRomans.emplace(80, "LXXX");
    //         mapRomans.emplace(90, "XC");
    //         mapRomans.emplace(100, "C");
    //         mapRomans.emplace(200, "CC");
    //         mapRomans.emplace(300, "CCC");
    //         mapRomans.emplace(400, "CD");
    //         mapRomans.emplace(500, "D");
    //         mapRomans.emplace(600, "DC");
    //         mapRomans.emplace(700, "DCC");
    //         mapRomans.emplace(800, "DCCC");
    //         mapRomans.emplace(900, "CM");
    //         mapRomans.emplace(1000, "M");
    //         mapRomans.emplace(2000, "MM");
    //         mapRomans.emplace(3000, "MMM");
    //
    //         if (mapRomans.count(num)) {
    //             return mapRomans[num];
    //         }
    //         int exp = 1;
    //         while (num != 0) {
    //             ans = mapRomans[(num % 10) * exp] + ans;
    //             num /= 10;
    //             exp *= 10;
    //         }
    //
    //         return ans;
    //     }

    string intToRoman(int num) {
        vector<int> ints = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> romans = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string ans; int i;
        for (i = 0; i < ints.size(); i++) {
            int bit = num / ints[i];
            for (; bit > 0; bit--) ans += romans[i];
            num %= ints[i];
        }
        return ans;
    }
};

int main() {
    string ans;
    int num = 1994;
    Solution sl;
    ans = sl.intToRoman(num);
    cout << ans << endl;

    return 0;
}
