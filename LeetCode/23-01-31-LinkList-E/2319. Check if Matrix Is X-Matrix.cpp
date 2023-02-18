#include "../LeetCode.h"

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int gridLen = grid.size();
        for (int i = 0; i < gridLen; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if ((i == j || i + j == gridLen - 1) && !grid[i][j]) {
                    return false;
                }
                if (!(i == j || i + j == gridLen - 1) && grid[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<int>> grid = { {5,0,0,1},{0,4,1,5},{0,5,2,0},{4,1,0,2} };
    Solution sl;
    bool ans;
    ans = sl.checkXMatrix(grid);
    cout << ans << endl;

    return 0;
}
