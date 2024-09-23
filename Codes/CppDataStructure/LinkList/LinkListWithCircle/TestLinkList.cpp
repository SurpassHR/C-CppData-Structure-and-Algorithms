#include <iostream>
#include "TestLinkList.h"
using namespace std;

LNode *RandomInsertList_L(ElemType x, LNode *next) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->elem = x;
    s->next = next;

    return s;
}

// 快慢指针验证单链表是否有环
bool hasCircle(LinkList head) {
    LNode *fast = head->next;
    LNode *slow = head->next;
    while (fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast==slow) return true;
    }

    return false;
}

int main() {
    LinkList L;
    // CreateEmptyList_L(L);
    LNode *node7 = RandomInsertList_L(14, NULL);
    LNode *node6 = RandomInsertList_L(19, node7);
    LNode *node5 = RandomInsertList_L(5, node6);
    LNode *node4 = RandomInsertList_L(40, node5);
    LNode *node3 = RandomInsertList_L(31, node4);
    LNode *node2 = RandomInsertList_L(7, node3);
    LNode *node1 = RandomInsertList_L(100, node2);
    LNode *head = RandomInsertList_L(-1, node1);

    node7->next =node3;

    cout << hasCircle(head) << endl;
    // cout << node1->elem << endl;

    return 0;
}
