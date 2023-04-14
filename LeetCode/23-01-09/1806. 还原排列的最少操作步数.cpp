#include "../LeetCode.h"
using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        int step = 0;

        // 创建长度为 n 的排列 perm
        vector<int> perm(n), arr(n);
        iota(perm.begin(), perm.end(), 0);
        iota(arr.begin(), arr.end(), 0);

        while (!isEqual(perm, arr) || step == 0) {
            arr = transition(arr);
            step += 1;
        }

        return step;
    }

    vector<int> transition(vector<int> v1) {
        vector<int> v2(v1.size());
        for (int i = 0; i < v1.size(); i++) {
            if (i % 2 == 0)
                v2[i] = v1[i / 2];
            else
                v2[i] = v1[v1.size() / 2 + (i - 1) / 2];
        }

        return v2;
    }

    bool isEqual(vector<int> v1, vector<int> v2) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }

        return true;
    }
};

int main(void) {
    int n, step;
    cin >> n;
    step = Solution().reinitializePermutation(n);
    cout << step << endl;

    return 0;
}
