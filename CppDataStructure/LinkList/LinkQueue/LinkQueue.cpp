#include "LinkQueue.h"
#include <iostream>
using namespace std;

Status MyLinkQueue::InitQueue() {
    q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!q.front) {
        return ERROR;
    }
    q.front->next = NULL;

    return OK;
}

Status MyLinkQueue::DestroyQueue() {
    while (q.front) {
        q.rear = q.front->next;
        free(q.front);
        q.front = q.rear;
    }

    return OK;
}

Status MyLinkQueue::EnQueue(ElemType val) {
    QueuePtr ptr = (QueuePtr)malloc(sizeof(QNode));
    if (!q.front || !ptr) {
        return ERROR;
    }
    ptr->data = val;
    ptr->next = NULL;
    q.rear->next = ptr;
    q.rear = ptr;
}
