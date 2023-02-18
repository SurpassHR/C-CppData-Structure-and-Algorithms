#include "../definition.h"

#ifndef _STACK_H_
#define _STACK_H_

#ifndef _STACK_DEF_
#define _STACK_DEF_

#define STACK_INIT_SIZE 100
#define STACKINCREACEMENT 10

typedef int ElemType;
// 顺序栈结构定义
typedef struct {
    ElemType *base;  // 栈底
    ElemType *top;   // 栈顶
    int stacksize;
} SqStack;

#endif

Status InitStack(SqStack &S);
Status StackEmpty();
Status Push(ElemType e);
Status Pop(ElemType &e);
Status Gettop();

#endif
