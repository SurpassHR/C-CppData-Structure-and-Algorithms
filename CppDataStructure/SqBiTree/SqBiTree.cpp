#include "SqBiTree.h"
#include <iostream>
using namespace std;

Status InitSqBinTree(struct TreeNode node[MAXSIZE]) {
    if (!node) {
        return ERROR;
    }

    for (int i = 0; i < MAXSIZE; i++) {
        node[i].isEmpty = true;
    }

    return OK;
}

Status HasLChild(TreeNode t[MAXSIZE], int idx) {
    if (!t || t[idx * 2].isEmpty) {
        return FALSE;
    } else {
        return TRUE;
    }
}

Status HasRChild(TreeNode t[MAXSIZE], int idx) {
    if (!t || t[idx * 2 + 1].isEmpty) {
        return FALSE;
    } else {
        return TRUE;
    }
}

Status GetParent(TreeNode t[MAXSIZE], int idx, ElemType &e) {
    if (!t || t[idx / 2].isEmpty) {
        return ERROR;
    }
    e = t[idx / 2].value;

    return OK;
}

Status GetLChild(TreeNode t[MAXSIZE], int idx, ElemType &e) {
    e = t[idx * 2].value;

    return OK;
}

Status GetRChild(TreeNode t[MAXSIZE], int idx, ElemType &e) {
    e = t[idx * 2 + 1].value;

    return OK;
}
