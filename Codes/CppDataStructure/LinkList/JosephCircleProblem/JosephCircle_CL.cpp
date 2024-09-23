#include <iostream>
#include "JosephCircle_CL.h"
using namespace std;

// 从数组创建链表（便于输入）
Status CreateList_RearInsert_FromArray_CL(LinkList &L, int num, int *a) {
    int i = 1;
    // 为空表第一个结点分配空间
    L = (LNode *)malloc(sizeof(LNode));
    if (!L) return ERROR;
    // 为新结点赋值
    L->No = i;
    L->Pwd = a[i-1];
    // 第一个结点既是头结点又是尾结点
    L->next = L;
    // 建立后续num-1个结点的连接
    for (i=2; i<=num; i++) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if (!s) return ERROR;
        s->No = i;
        s->Pwd = a[i-1];
        s->next = L->next;
        L->next = s;
        L = s;
    }
    return OK;
}

// 尾插法新建循环链表，创建仅有尾指针的循环单链表，传入对空尾指针的引用
Status CreateList_RearInsert_CL(LinkList &L, int num) {
    int i = 1;
    // 为空表第一个结点分配空间
    L = (LNode *)malloc(sizeof(LNode));
    if (!L) return ERROR;
    // 为新结点赋值
    L->No = i;
    cout << "请输入第" << i << "个玩家的密码: ";
    cin >> L->Pwd;
    // 第一个结点既是头结点又是尾结点
    L->next = L;
    // 建立后续num-1个结点的连接
    for (i=2; i<=num; i++) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if (!s) return ERROR;
        s->No = i;
        cout << "请输入第" << i << "个玩家的密码: ";
        cin >> s->Pwd;
        s->next = L->next;
        L->next = s;
        L = s;
    }

    return OK;
}

// 尾插法新建循环链表，返回一个尾指针
LinkList CreateList_RearInsert_CL(int num) {
    LinkList CLRear;
    int i = 1;
    // 创建第一个结点
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (!s) {
        cout << "Memory allocation error!" << endl;
        return NULL;
    }
    s->No = i;
    cout << "请输入第" << i << "个玩家的密码: ";
    cin >> s->Pwd;
    // 第一个结点作为头结点和尾结点，循环自己指向自己
    s->next = s;
    CLRear = s;
    // 创建后续num-1个结点
    for (i=2; i<=num; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        if (!s) {
            cout << "Memory allocation error!" << endl;
            return NULL;
        }
        s->No = i;
        cout << "请输入第" << i << "个玩家的密码: ";
        cin >> s->Pwd;
        // 新结点指向后继，头结点为原尾结点的next
        s->next = CLRear->next;
        // 将新结点并入循环单链表
        CLRear->next = s;
        // 新节点成为新的尾结点
        CLRear = s;
    }

    return CLRear;
}

Status PrintList_CL(LinkList L) {
    // 非空表判断
    if (!L) return ERROR;
    // 遍历，从头结点开始
    LNode *tmp, *LHead;
    tmp = LHead = L->next;
    while (tmp) {
        cout << "玩家编号: " << tmp->No << ", 玩家密码: " << tmp->Pwd << ";\t";
        tmp = tmp->next;
        if (tmp == LHead) break;
    }
    cout << endl;

    return OK;
}

// 时间复杂度O(1)的取巧结点删除算法
Status ListDelete_O1_CL(LinkList &L, LNode *node_to_del) {
    if (!node_to_del) return ERROR;

    node_to_del->No = node_to_del->next->No;
    node_to_del->Pwd = node_to_del->next->Pwd;
    LNode *q = node_to_del->next;
    node_to_del->next = q->next;
    free(q);

    return OK;
}

// 从头遍历的时间复杂度O(n)的结点删除算法
Status ListDelete_On_CL(LinkList &L, LNode *node_to_del) {
    if (!node_to_del) return ERROR;

    // 遍历，tmp为待删除结点的前驱结点
    LNode *tmp = L->next;
    while (tmp->next != node_to_del) tmp = tmp->next;
    tmp->next = node_to_del->next;
    // 单独说明被删除结点为尾指针指向的结点时
    if (node_to_del == L) L = tmp;
    // 单独说明尾指针所指向结点为唯一结点时
    free(node_to_del);
    //PrintList_CL(L);

    return OK;
}

// Solution 1
void PlayGame_s1(LinkList &L, int number, int init_pwd) {
    int pwd = init_pwd;
    LNode *tmp, *tmp_to_del;
    tmp = L->next;
    while (number) {
        if (number>1) pwd = pwd % number ? pwd % number : pwd;
        for (int i=1; i<pwd; i++) tmp = tmp->next;
        cout << tmp->No << "\t";
        pwd = tmp->Pwd;
        tmp_to_del = tmp;
        tmp = tmp->next;
        ListDelete_On_CL(L, tmp_to_del);
        number --;
    }
    cout << endl;

    return ;
}

// Solution 2
void PlayGame_s2(LinkList &L, int number, int pwd) {
    LNode *pre_tmp, *tmp;
    pre_tmp = L;
    tmp = pre_tmp->next;
    while (number>0) {
        pwd = pwd % number ? pwd % number : pwd;
        for (int i=1; i<pwd; i++) pre_tmp = pre_tmp->next;
        tmp = pre_tmp->next;
        cout << tmp->No << "\t";
        pwd = tmp->Pwd;
        pre_tmp->next = tmp->next;
        free(tmp);
        tmp = pre_tmp->next;
        number --;
    }
    cout << endl;
    //cout << tmp->No << endl;
    //free(tmp);

    return ;
}

int main() {
    /*
       LinkList L1;
       L1 = CreateList_RearInsert_CL(3);
       LinkList L2;
       CreateList_RearInsert_CL(L2, 3);
       PrintList_CL(L1);
       PrintList_CL(L2);
       */
    // 给出题目
    // j[1]=3, j[2]=8, j[3]=1, j[4]=22, j[5]=4, j[6]=9, j[7]=15, 初始密码5
    // 依照题目创建循环单链表
    LinkList J1, J2;
    int joseph_circle[] = {3, 8, 1, 22, 4, 9, 15};
    int listsize =  sizeof(joseph_circle)/sizeof(joseph_circle[0]);
    CreateList_RearInsert_FromArray_CL(J1, listsize, joseph_circle);
    CreateList_RearInsert_FromArray_CL(J2, listsize, joseph_circle);
    // PrintList_CL(J);
    PlayGame_s1(J1, listsize, 5);
    PlayGame_s2(J2, listsize, 5);
    // PrintList_CL(J);

    return 0;
}
