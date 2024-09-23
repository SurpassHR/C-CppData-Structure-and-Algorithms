#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct BiTNode {
    int val;
    struct BiTNode* left, * right;
    BiTNode(int x): val(x), left(nullptr), right(nullptr) { }
} BiTNode;

class Solution {
public:
    void PreOrderTraversal_Rec(BiTNode* root) {
        if (!root) return;
        cout << root->val << " ";
        PreOrderTraversal_Rec(root->left);
        PreOrderTraversal_Rec(root->right);
    }

    void PreOrderTraversal_NoneRec(BiTNode* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            cout << root->val << " ";
            return;
        }
        BiTNode* cur = root;
        stack<BiTNode*> st;
        st.push(cur);
        while (!st.empty()) {
            cur = st.top();
            st.pop();
            cout << cur->val << " ";
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
    }

    void InOrderTraversal_Rec(BiTNode* root) {
        if (!root) return;
        InOrderTraversal_Rec(root->left);
        cout << root->val << " ";
        InOrderTraversal_Rec(root->right);
    }

    void InOrdertraversal_NoneRec(BiTNode* root) {
        if (!root) return;
        if (!root->left || !root->right) {
            cout << root->val << " ";
            return;
        }
        BiTNode* cur = root;
        stack<BiTNode*> st;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }

    void PostOrderTraversal_Rec(BiTNode* root) {
        if (!root) return;
        PostOrderTraversal_Rec(root->left);
        PostOrderTraversal_Rec(root->right);
        cout << root->val << " ";
    }

    void PostOrderTraversal_NoneRec(BiTNode* root) {
        if (!root) return;
        if (!root->left || !root->right) {
            cout << root->val << " ";
            return;
        }
        BiTNode* cur = root;
        stack<BiTNode*> st1, st2;
        st1.push(cur);
        while (!st1.empty()) {
            cur = st1.top();
            st1.pop();
            st2.push(cur);
            if (cur->left) st1.push(cur->left);
            if (cur->right) st1.push(cur->right);
        }
        while (!st2.empty()) {
            cur = st2.top();
            st2.pop();
            cout << cur->val << " ";
        }
    }

    void LevelOrderTaversal(BiTNode* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            cout << root->val << " ";
            return;
        }
        BiTNode* cur = root;
        queue<BiTNode*> q;
        q.push(cur);
        while (!q.empty()) {
            int n = q.size();
            while (n > 0) {
                // 出队
                cur = q.front();
                q.pop();
                cout << cur->val << " ";
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                n--;
            }
        }
    }
};

int main() {
    cout << (nullptr == nullptr) << endl;
    BiTNode* node1 = new BiTNode(1);
    BiTNode* node2 = new BiTNode(2);
    BiTNode* node3 = new BiTNode(3);
    BiTNode* node4 = new BiTNode(4);
    BiTNode* node5 = new BiTNode(5);
    node1->left = node2; node1->right = node3;
    node2->left = node4;
    node4->right = node5;

    Solution sl;

    cout << "PreOrder traversal:" << endl;
    sl.PreOrderTraversal_Rec(node1);
    cout << "\n";
    sl.PreOrderTraversal_NoneRec(node1);
    cout << "\n";

    cout << "InOrder traversal:" << endl;
    sl.InOrderTraversal_Rec(node1);
    cout << "\n";
    sl.InOrdertraversal_NoneRec(node1);
    cout << "\n";

    cout << "PostOrder traversal:" << endl;
    sl.PostOrderTraversal_Rec(node1);
    cout << "\n";
    sl.PostOrderTraversal_NoneRec(node1);
    cout << "\n";

    cout << "LevelOrder traversal:" << endl;
    sl.LevelOrderTaversal(node1);
    cout << "\n";

    return 0;
}
