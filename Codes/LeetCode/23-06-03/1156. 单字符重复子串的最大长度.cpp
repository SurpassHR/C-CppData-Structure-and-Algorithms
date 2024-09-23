#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> lenVersion(text.size(), 0);
        lenVersion[0] = 1;
        int count = 1;
        for (int i = 1; i < text.size(); i++) {
            if (text[i] == text[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            lenVersion[i] = count;
        }
        for (int i = 0; i < lenVersion.size(); i++) {
            cout << lenVersion[i] << " ";
        }
        cout << endl;
        // 找到子串最长的尾部索引
        int maxSubstrTail = 0;
        int maxSubstrLen = 1;
        for (int i = 1; i < lenVersion.size(); i++) {
            // 同字符子串到头
            if (text[i] != text[i - 1]) {

            }
            if (lenVersion[i] > maxSubstrLen) {
                maxSubstrLen = lenVersion[i];
            }
        }

        return int();
    }
};

int main() {
    string text = "";
    cin >> text;
    Solution().maxRepOpt1(text);
    return 0;
}
