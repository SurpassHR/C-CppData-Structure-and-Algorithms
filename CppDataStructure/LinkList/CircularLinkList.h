#include "../definition.h"

#ifndef _CIRCULARLINKLIST_H_
#define _CIRCULARLINKLIST_H_

#ifndef _CL_DEF_
#define _CL_DEF_

typedef int ElemType;
typedef struct LNode {
    ElemType elem;
    struct LNode *next;
} LNode, *LinkList;

#endif

LinkList CreateList_RearInsert_CL(int num);
Status CreateList_RearInsert_FromArray_CL(LinkList &L, int a[]);
Status CreateList_RearInsert_CL(LinkList &L, int num);
Status ListDelete_O1_CL(LinkList &L, LNode *node_to_del);
Status ListDelete_On_CL(LinkList &L, LNode *node_to_del);
Status PrintList_CL(LinkList L);

#endif
