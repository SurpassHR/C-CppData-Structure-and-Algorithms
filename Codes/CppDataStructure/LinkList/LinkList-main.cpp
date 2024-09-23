// 不带头结点的单链表
#include <iostream>
#include "LinkList.h"
using namespace std;

int main() {
    LinkList L;
    while (1) {
        Menu(L);
        getchar();
        cout << "Press any key to continue ...";
        getchar();
    }
    /*
    // 创建单链表头指针
    LinkList L1, L2;
    // Status CreateEmptyList_L(LinkList L); 
    // cout << CreateEmptyList_L(L) << endl;
    CreateList_FrontInsert_L(L1, 3);
    PrintList_L(L1);
    CreateList_RearInsert_L(L2, 3);
    PrintList_L(L2);
    */
    return 0;
}
