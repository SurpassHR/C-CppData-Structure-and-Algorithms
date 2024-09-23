// 链表基本定义
#include "../definition.h"

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef int ElemType;
typedef struct LNode {
    ElemType elem;
    struct LNode *next;
} LNode, *LinkList;


#ifndef _TESTLINKLIST_H_

void Menu(LinkList &L);
Status CreateEmptyList_L(LinkList &L);
Status CreateList_FrontInsert_L(LinkList &L, int num);
Status CreateList_RearInsert_L(LinkList &L, int num);
LinkList CreateList_RearInsert(int num);
Status InsertList_L(LinkList &L, int i, ElemType x);
Status LocateElem_L(LinkList L, int &i, ElemType x);
Status ListDelete_L(LinkList &L, int i, ElemType &x);
Status PrintList_L(LinkList L);
Status DestroyList_L(LinkList &L);

#endif

#endif
