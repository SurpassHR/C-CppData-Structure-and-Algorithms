/* 二叉树顺序存储（只适用于完全二叉树） */
#include "../definition.h"

#ifndef _SEQBINTREE_H_
#define _SEQBINTREE_H_

#define MAXSIZE 100

typedef int ElemType;
struct TreeNode {
    ElemType value;
    bool isEmpty;
};

Status InitSqBinTree(TreeNode t[MAXSIZE]);
Status HasLChild(TreeNode t[MAXSIZE], int idx);
Status HasRChild(TreeNode t[MAXSIZE], int idx);
Status GetParent(TreeNode t[MAXSIZE], int idx, ElemType &e);
Status GetLChild(TreeNode t[MAXSIZE], int idx, ElemType &e);
Status GetRChild(TreeNode t[MAXSIZE], int idx, ElemType &e);

#endif
