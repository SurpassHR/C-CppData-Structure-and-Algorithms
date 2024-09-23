#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    bool isNumber(string str) {
        if (str[0] >= '0' && str[0] <= '9') return true;
        else return false;
    }
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        if (array.size() <= 1) return {};
        if (array.size() == 2) {
            if (isNumber(array[0]) && !isNumber(array[1]) || isNumber(array[1]) && !isNumber(array[0])) return array;
        }
        // 暴力法
        vector<string> ans;
        // 数组长度
        int n = array.size();
        for (int i = 0; i < n; i++) {
            // 奇数项数组一定不存在数字个数等于字幕个数的情况
            for (int j = i; j < n - 1; j += 2) {
                // 取当前子数组，保留备份
                vector<string> sub1(j - i), sub2(j - i);
                copy(array.begin() + i, array.begin() + j, sub1.begin());
                copy(array.begin() + i, array.begin() + j, sub2.begin());
                // 考察当前子数组
                sort(sub1.begin(), sub1.end());
                int subNumberNum = 0;
                // 当前子数组内数字个数
                for (auto it = sub1.begin(); it != sub1.end() && ((*it)[0] >= '0' && (*it)[0] <= '9'); it++) subNumberNum++;
                if ((2 * subNumberNum == j - i) && j - i > ans.size()) ans = sub2;
            }
        }
        return ans;
    }
};

int main() {
    // vector<string> array = { "A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M" };
    // vector<string> array = { "A","1" };
    vector<string> array = { "C","u","49","29","o","68","k","r","E","26","24","W","F","w","13","53","C","H","V","s","13","S","l","z","U","a","50","25","f","E","7","25","o","50","e","R","36","93","77","47","M","36","84","46","82","w","L","46","54","58","73","85","18","D","m","c","46","j","U","i","P","49","49","i","N","P","h","40","o","54","47","24","7","H","100","92","6","10","66","74","47","35","O","41","Z","9","37","S","A","g","78","C","X","1","28","B","s","R","81","q" };
    vector<string> ans;
    Solution sl;
    ans = sl.findLongestSubarray(array);
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
