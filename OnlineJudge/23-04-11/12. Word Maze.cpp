#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<char>> maze; // 迷宫矩阵
vector<vector<bool>> vis; // 是否被访问矩阵

/**
 * @brief DFS查找四个方向的下一个字符
 * @param left 剩余带查找字符串
 * @param x 迷宫中横坐标
 * @param y 迷宫中纵坐标
*/
bool getNextChar(string left, int x, int y) {
    if (maze[x][y] != left[0]) { // 当前位置不匹配
        return false;
    }
    if (left.size() == 1) { // 在上一步的基础上潜条件为maze[x][y] == left[0]
        return true;
    }
    vis[x][y] = true;
    bool found = false;
    // 继续搜索四个方向
    if (x > 0 && !vis[x - 1][y]) { // 向左
        found |= getNextChar(left.substr(1), x - 1, y);
    }
    if (x < n - 1 && !vis[x + 1][y]) { // 向右
        found |= getNextChar(left.substr(1), x + 1, y);
    }
    if (y > 0 && !vis[x][y - 1]) { // 向上
        found |= getNextChar(left.substr(1), x, y - 1);
    }
    if (y < m - 1 && !vis[x][y + 1]) { // 向下
        found |= getNextChar(left.substr(1), x, y + 1);
    }
    if (!found) vis[x][y] = false;

    return found;
}

int main() {
    string W, row;

    // 读入数据
    cin >> n >> m;
    cin >> W;

    // 初始化二维可变数组内存空间
    maze.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m));

    // 读入迷宫
    for (int i = 0; i < n && cin >> row; i++) {
        maze[i].assign(row.begin(), row.end());
    }

    // DBG
    // for (auto it_row : maze) {
    //     for (auto it : it_row) {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }

    // 找到开头第一个字母的位置
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (getNextChar(W, i, j)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}