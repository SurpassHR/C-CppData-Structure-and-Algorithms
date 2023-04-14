#include "../../definition.h"

#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

typedef int ElemType;

// 结点结构定义
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

// 链表结构定义：包含头尾指针的单链队列
typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

class MyLinkQueue {
   public:
    Status InitQueue();
    Status DestroyQueue();
    Status EnQueue(ElemType val);

   private:
    LinkQueue q;
};

#endif
