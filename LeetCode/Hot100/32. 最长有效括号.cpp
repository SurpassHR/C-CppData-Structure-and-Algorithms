#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                for (int j = i; j+1 < s.size(); j+=2) {
                    string str(s[j]);
                    if (str + s[j+1])
                }
            }
        }
    }
};

int main() {
    return 0;
}