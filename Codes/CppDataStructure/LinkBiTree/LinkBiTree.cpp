#include "LinkBiTree.h"
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// 先序遍历
Status PreOrder(BiTNode* node) {
    BiTNode* cur = node;
    stack<BiTNode*> st;
    st.push(cur);
    while (!st.empty()) {
        cur = st.top();
        st.pop();
        cout << cur->val << " ";
        if (cur->right) st.push(cur->right);
        if (cur->left) st.push(cur->left);
    }
    cout << "\n";
    return OK;
}

// 中序遍历
Status InOrder(BiTNode* node) {
    BiTNode* cur = node;
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
    cout << "\n";
    return OK;
}

// 后序遍历
Status PostOrder(BiTNode* node) {
    BiTNode* cur = node;
    stack<BiTNode*> st;
    vector<int> ans;
    st.push(cur);
    while (!st.empty()) {
        cur = st.top();
        st.pop();
        ans.push_back(cur->val);
        if (cur->left) st.push(cur->left);
        if (cur->right) st.push(cur->right);
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";
    return OK;
}

// 使用双栈的后序遍历
Status PostOrder_DoubleStack(BiTNode* node) {
    BiTNode* cur = node;
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
        cout << st2.top()->val << " ";
        st2.pop();
    }
    cout << "\n";
    return OK;
}

// 递归后序遍历
Status PostOrder_Recursive(BiTNode* node) {
    if (!node) return OK;
    PostOrder_Recursive(node->left);
    PostOrder_Recursive(node->right);
    cout << node->val << " ";
    return OK;
}

// 层序遍历
Status LevelOrder(BiTNode* node);
