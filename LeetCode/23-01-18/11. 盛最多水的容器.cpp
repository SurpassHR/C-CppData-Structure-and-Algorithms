#include "../LeetCode.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0 || height.size() == 1) return 0;
        if (height.size() == 2) return min(height[0], height[1]);
        int i, j, m = 0;
        for (i = 0, j = height.size() - 1; i < j;) {
            m = max((j - i) * min(height[i], height[j]), m);
            if (height[i] < height[j]) i++;
            else j--;
        }

        return m;
    }
};

int main(void) {
    vector<int> height;
    // height = { 1,8,6,2,5,4,8,3,7 };
    // height = { 1,1 };
    height = { 2,3,4,5,18,17,6 };
    int ans;
    Solution sl;
    ans = sl.maxArea(height);
    cout << ans << endl;
    return 0;
}
