#include "../../definition.h"

#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef int ElemType;

// 栈结点结构定义
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StNode, *StackPtr;

// 栈结构定义：包含栈顶指针和栈底指针的链栈
typedef struct {
    StackPtr top;
    StackPtr bottom;
    int length;
} LinkStack;

class MyLinkStack {
   public:
    Status InitStack();
    Status DestroyStack();
    Status Push(ElemType val);
    Status Pop(ElemType &e);
    Status PrintStack();

   private:
    LinkStack st;
};

#endif
