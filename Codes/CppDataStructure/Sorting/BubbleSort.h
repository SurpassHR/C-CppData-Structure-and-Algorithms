#include "../definition.h"

#ifndef _BUBBLESORT_H_

typedef int ElemType;
// 动态顺序表
typedef struct {
    ElemType *a;
    int len;
} Arr;

typedef struct node {
    ElemType data;
    node *next;
} Head, *Node;
typedef struct {
    Head head;
    int len;
} LinkList;

void Swap(ElemType &a, ElemType &b);
Arr CreateSeqList(int a[], int len);
LinkList CreateLinkList(ElemType a[], int len);
Arr CopyArr(Arr arr);
// 顺序表冒泡排序
Status BubbleSort_S(Arr &a);
// 链表冒泡排序
Status BubbleSort_L(LinkList &L);

#endif
