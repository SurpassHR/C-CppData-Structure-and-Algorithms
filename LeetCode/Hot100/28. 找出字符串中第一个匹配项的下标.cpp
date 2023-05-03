#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getNext(string haystack) {
        int strLen = haystack.size();
        vector<int> next(strLen, 0);
        next[0] = 0;
        next[1] = 1;
        // 从2开始求next值
        int i = 2;
        for (; i < strLen; i++) {
            string substr = haystack.substr(0, i);
            int j = substr.size() - 1;
            while ((j >= 1) && (substr.substr(0, j).compare(substr.substr(substr.size() - j, j)) != 0)) {
                j--;
            }
            next[i] = j + 1;
        }
        return next;
    }

    vector<int> getNextVal(string haystack, vector<int> next) {
        vector<int> nextVal(haystack.size(), 0);
        nextVal[0] = 0;
        nextVal[1] = 1;
        for (int i = 2; i < next.size(); i++) {
            if (haystack[i] == haystack[next[i] - 1]) {
                nextVal[i] = nextVal[next[i] - 1];
            } else {
                nextVal[i] = next[i];
            }
        }
        return nextVal;
    }

    int strStr(string haystack, string needle) {
        return 0;
    }
};

int main() {
    Solution sl;
    string haystack = "abaabcac";
    vector<int> next = sl.getNext(haystack);
    for (int it : next) {
        cout << it << " ";
    }
    cout << endl;
    vector<int> nextVal = sl.getNextVal(haystack, next);
    for (int it : nextVal) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
