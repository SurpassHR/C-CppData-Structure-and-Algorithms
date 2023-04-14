/* 冒泡排序（升序） */

#include <iostream>
#include "BubbleSort.h"
using namespace std;

void Swap(ElemType &a, ElemType &b) {
    ElemType tmp = a;
    a = b;
    b = tmp;
}

Arr CreateSeqList(ElemType a[], int len) {
    Arr arr;
    arr.a = (ElemType *)malloc(len * sizeof(ElemType));
    if (!arr.a) {
        exit(-1);
    }
    arr.len = len;
    for (int i = 0; i < len; i++) {
        arr.a[i] = a[i];
    }

    return arr;
}

LinkList CreateLinkList(ElemType a[], int len) {
    LinkList L;
    L.head.next = NULL;
    Node tmp = &(L.head);
    for (int i = 0; i < len; i++) {
        Node p = (Node)malloc(sizeof(Head));
        if (!p)
            exit(-1);
        p->data = a[i];
        tmp->next = p;
        p->next = NULL;
        tmp = p;
    }
    L.len = len;
    return L;
}

Arr CopyArr(Arr arr) {
    Arr arr_cp;
    arr_cp.a = (ElemType *)malloc(arr.len * sizeof(ElemType));
    if (!arr_cp.a) {
        exit(-1);
    }
    arr_cp.len = arr.len;
    for (int i = 0; i < arr.len; i++) {
        arr_cp.a[i] = arr.a[i];
    }
    return arr_cp;
}

// 顺序表冒泡排序
Status BubbleSort_S(Arr &arr) {
    int tmp, *a = arr.a;
    bool flag = false;
    for (int j = 0; j < arr.len; j++) {
        flag = false;
        for (int i = arr.len - 1; i > j; i--) {
            if (a[i - 1] > a[i]) {
                Swap(a[i - 1], a[i]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
    return OK;
}

// 链表冒泡排序
Status BubbleSort_L(LinkList &L) {
    Node p = L.head.next, q = L.head.next->next;
    bool flag = false;
    for (int j = 0; j < L.len; j++) {
        flag = false;
        p = L.head.next, q = L.head.next->next;
        for (int i = 0; i < L.len - j && q != NULL; i++, p = p->next, q = q->next) {
            if (p->data > q->data) {
                Swap(p->data, q->data);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
    return OK;
}
int main() {
    ElemType a[5] = {5, 4, 9, 2, 1};
    Arr arr1 = CreateSeqList(a, 5);
    LinkList L1 = CreateLinkList(a, 5);

    // 顺序表冒泡
    BubbleSort_S(arr1);
    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
        cout << arr1.a[i] << "\t";
    }
    cout << endl;

    // 链表冒泡
    BubbleSort_L(L1);
    Node tmp = L1.head.next;
    for (int i = 0; i < L1.len && tmp != NULL; i++) {
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
    cout << endl;

    return 0;
}
