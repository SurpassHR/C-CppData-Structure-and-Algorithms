#include "../definition.h"

#ifndef _LINKBITREE_H_
#define _LINKBITREE_H_

typedef int ElemType;

// 二叉树的链式结构声明
typedef struct BiTNode {
    ElemType val;
    struct BiTNode *lchild, *rchild;
} BiTree, *BiTNode;

// 层序遍历需要的链队列
typedef struct LinkNode {
    BiTNode *node;
    struct LinkNode *next;
} LinkQueue;

// 先序遍历
Status PreOrder(BiTNode node);

// 中序遍历
Status InOrder(BiTNode node);

// 后序遍历
Status PostOrder(BiTNode node);

// 层序遍历
Status LevelOrder(BiTNode node);

#endif
