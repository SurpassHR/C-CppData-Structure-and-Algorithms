#include "LinkBiTree.h"
#include <iostream>
using namespace std;

void OprtMenu() {
    return;
}

int main() {
    BiTNode* node1 = new BiTNode;
    node1->val = 1; node1->left = node1->right = nullptr;
    BiTNode* node2 = new BiTNode;
    node2->val = 2; node2->left = node2->right = nullptr;
    BiTNode* node3 = new BiTNode;
    node3->val = 3; node3->left = node3->right = nullptr;
    BiTNode* node4 = new BiTNode;
    node4->val = 4; node4->left = node4->right = nullptr;
    BiTNode* node5 = new BiTNode;
    node5->val = 5; node5->left = node5->right = nullptr;

    node1->left = node2; node1->right = node3;
    node2->left = node4;
    node4->right = node5;

    cout << "PreOrder Traverse:" << endl;
    PreOrder(node1);

    cout << "InOrder Traverse:" << endl;
    InOrder(node1);

    cout << "PostOrder Traverse:" << endl;
    PostOrder(node1);
    PostOrder_DoubleStack(node1);
    PostOrder_Recursive(node1);
    cout << "\n";

    return 0;
}
