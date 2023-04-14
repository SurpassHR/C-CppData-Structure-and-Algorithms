#include "../definition.h"

#ifndef _LINKBITREE_H_
#define _LINKBITREE_H_

typedef int ElemType;

// 二叉树的链式结构声明
typedef struct BiTNode {
    ElemType val;
    struct BiTNode* left, * right;
} *BiTree, BiTNode;

// 层序遍历需要的链队列
typedef struct LinkNode {
    BiTNode* node;
    struct LinkNode* next;
} LinkQueue;

/* 使用迭代完成的二叉树遍历 */
// 先序遍历
Status PreOrder(BiTNode* node);

// 中序遍历
Status InOrder(BiTNode* node);

// 后序遍历
Status PostOrder(BiTNode* node);

// 使用双栈的后序遍历
Status PostOrder_DoubleStack(BiTNode* node);

// 递归后序遍历
Status PostOrder_Recursive(BiTNode* node);

// 层序遍历
Status LevelOrder(BiTNode* node);

#endif
