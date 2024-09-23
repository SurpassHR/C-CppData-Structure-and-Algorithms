#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int timer = 0;
        float* p1 = new float(2);
        float* p2 = new float[2];
        cout << *p1 << endl;
        int k = 2;
        while (k > 0) {
            cout << *p2 << " ";
            p2++;
            k--;
        }
        cout << endl;
        return 0;
    }
};

int main() {
    vector<char> a = {};
    Solution().leastInterval(a, 0);

    return 0;
}
