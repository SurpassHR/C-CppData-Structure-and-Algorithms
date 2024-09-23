// 不带头结点的单链表
#include <iostream>
#include "LinkList.h"
using namespace std;

Status CreateEmptyList_L(LinkList &L) {
    // 创建空表第一个结点
    LNode *node = (LNode *)malloc(sizeof(LNode));
    if (!node) exit(OVERFLOW);
    // 使头指针L指向第一个结点
    node->elem = 0;
    node->next = NULL;
    L = node;
    return OK;
}

// 头插法创建单链表
Status CreateList_FrontInsert_L(LinkList &L, int listsize) {
    // 计数
    int i = 1;
    // 为第一个结点分配空间
    LNode *node = (LinkList)malloc(sizeof(LNode));
    if (!node) exit(OVERFLOW);
    cout << "请输入第" << i << "个元素的值: ";
    cin >> node->elem;
    node->next = NULL;
    L = node;
    // 头插后n-1个结点
    for (i=2 ; i<=listsize; i++) {
        node = (LNode *)malloc(sizeof(LNode));
        if (!node) exit(OVERFLOW);
        cout << "请输入第" << i << "个元素的值: ";
        cin >> node->elem;
        node->next = L;
        L = node;
    }

    return OK;
}

// 尾插法创建单链表
Status CreateList_RearInsert_L(LinkList &L, int listsize) {
    // 计数
    int i = 1;
    // 临时头尾指针
    LNode *LHead, *LTail;
    // 为第一个结点分配空间
    LNode *node = (LNode *)malloc(sizeof(LNode));
    if (!node) exit(OVERFLOW);
    cout << "请输入第" << i << "个元素的值: ";
    cin >> node->elem;
    node->next = NULL;
    LHead = LTail = node;
    L = LHead;
    for (i=2 ; i<=listsize; i++) {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        if (!node) exit(OVERFLOW);
        cout << "请输入第" << i << "个元素的值: ";
        cin >> node->elem;
        node->next = NULL;
        LTail->next = node;
        LTail = node;
    }

    return OK;
}

LinkList CreateList_RearInsert(int num) {
    LinkList L;
    return L;
}

Status InsertList_L(LinkList &L, int i, ElemType x) {
    LNode *p = L;
    int count = 1;
    // 判断插入位置是否合法
    if (i<1) return ERROR;
    // 创建结点
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->elem = x;
    if (!s) return ERROR;
    // 如果插在首位
    if (i == 1) {
        s->next = L;
        L = s;
        return OK;
    }
    // 不在首位，合法或者大于当前长度-1
    // 查找位序i-1
    while (p && count<i-1) {
        p = p->next;
        count ++;
    }
    if (!p || count>i) return ERROR;
    s->next = p->next;
    p->next = s;

    return OK;
}

Status LocateElem_L(LinkList L, int &i, ElemType x) {
    return OK;
}

Status ListDelete_L(LinkList L, int i, ElemType &x) {
    return OK;
}

Status PrintList_L(LinkList L) {
    if (!L) return ERROR;
    LNode *tmp = L;
    while (tmp) {
        cout << tmp->elem << "\t";
        tmp = tmp->next;
    }
    cout << endl;

    return OK;
}

Status DestroyList_L(LinkList &L) {
    LinkList tmp = L;
    free(tmp);
    L = NULL;

    return OK;
}

void Menu(LinkList &L) {
    system("clear");
    cout << "操作菜单" << endl;
    cout << "1.创建空单链表" << endl;
    cout << "2.头插法创建单链表" << endl;
    cout << "3.尾插法创建单链表" << endl;
    cout << "4.插入元素" << endl;
    cout << "5.删除元素" << endl;
    cout << "6.修改元素" << endl;
    cout << "7.打印链表" << endl;
    cout << "8.销毁链表" << endl;
    cout << "9.退出" << endl;
    cout << "Tips:多次创建链表前先销毁之前创建的链表" << endl;
    int cond;
    Status sta;
    cout << "请输入要进行的操作: ";
    cin >> cond;
    switch (cond) {
        case 1:
            CreateEmptyList_L(L);
            break;
        case 2:
            int head_ins_create_num;
            cout << "请输入要插入元素的个数: ";
            cin >> head_ins_create_num;
            CreateList_FrontInsert_L(L, head_ins_create_num);
            break;
        case 3:
            int rear_ins_create_num;
            cout << "请输入要插入元素的个数: ";
            cin >> rear_ins_create_num;
            CreateList_RearInsert_L(L, rear_ins_create_num);
            break;
        case 4:
            int insert_loc;
            ElemType insert_elem;
            cout << "请输入要插入元素的位置: ";
            cin >> insert_loc;
            cout << "请输入要插入元素的数值: ";
            cin >> insert_elem;
            sta = InsertList_L(L, insert_loc, insert_elem);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            PrintList_L(L);
            break;
        case 8:
            DestroyList_L(L);
            break;
        case 9:
            system("clear");
            exit(0);
            break;
        default:
            cout << "错误的选项!" << endl;
            break;
    }
}
