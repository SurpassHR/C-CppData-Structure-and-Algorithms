#include "../definition.h"

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#ifndef _SQ_DEF_
#define _SQ_DEF_

#define INIT_SIZE 100
#define INCREASEMENT 10

#endif

typedef int ElemType;
typedef struct {
    ElemType* elem;  // base address
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList &L);
Status InsertList_Sq(SqList &L, int i, ElemType x);
Status ListDelete_Sq(SqList &L, int i, ElemType &x);
Status LocateElem_Sq(SqList L, int &i, ElemType x);
Status DestroyList_Sq(SqList &L);
Status ModList_Sq(SqList &L, int i, ElemType x);
Status PrintList_Sq(SqList L);
Status ReverseList_Sq(SqList &L, int LLeft, int LRight, int LLength);
void Menu(SqList &L);

#endif
