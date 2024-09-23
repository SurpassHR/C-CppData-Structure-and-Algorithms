#include <iostream>
#include <queue>
#include <deque>
#include <stack>

using namespace std;


/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x): val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) { }
};


int main() {
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    q.push(root); q.push(node1);
    while (!q.empty()) {
        cout << q.front()->val << " ";
        q.pop();
    }
    cout << "\n";
    stack<TreeNode*> st;
    st.push(root); st.push(node1);
    while (!st.empty()) {
        cout << st.top()->val << " ";
        st.pop();
    }
    cout << "\n";
    return 0;
}
