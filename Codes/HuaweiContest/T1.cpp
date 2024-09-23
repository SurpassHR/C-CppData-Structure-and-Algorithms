#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int GetUniqueSum(const vector<int>& arrs)
    {
        int count = 0;
        map<int, int> m;
        for (int i = 0; i < arrs.size(); i++) {
            m[arrs[i]]++;
        }
        for (int i = 0; i < arrs.size(); i++) {
            if (m[arrs[i]] == 1) {
                count += arrs[i];
            }
        }
        return count;
    }
};

int main() {
    vector<int> arrs = { 35,57,35,20,30 };
    int ret = Solution().GetUniqueSum(arrs);
    cout << ret << endl;
    return 0;
}