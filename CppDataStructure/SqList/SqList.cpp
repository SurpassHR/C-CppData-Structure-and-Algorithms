#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "SqList.h"
using namespace std;

Status InitList_Sq(SqList &L) {
    L.elem = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
    // 内存空间分配失败
    if (!L.elem) exit(OVERFLOW);
    L.listsize = INIT_SIZE;
    L.length = 0;

    return OK;
}

Status InsertList_Sq(SqList &L, int i, ElemType x) {
    ElemType *q, *p;
    // 检查插入位置是否合法
    if (i<1 || i>L.length+1) return ERROR;
    // 检查顺序表空是否分配足够空间
    if (L.length+1 > L.listsize) {
        // 数据存储位置新基址
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.length + INCREASEMENT) * sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += INCREASEMENT;
    }
    // 寻找插入位置
    q = &(L.elem[i-1]);
    for (p=&(L.elem[L.length-1]); p>=q; p--)
        *(p+1) = *p;
    L.elem[i-1] = x;
    L.length ++;

    return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &x) {
    ElemType *q, *p;
    // 检查删除位置是否合法
    if (i<1 || i>L.length) return ERROR;
    // 寻找删除位置
    q = &(L.elem[i-1]);
    // 取出待删除元素
    x = L.elem[i-1];
    // 逐位前移删除
    for (p=q; p<=&(L.elem[L.length]); p++)
        *p = *(p+1);
    L.length --;

    return OK;
}

Status LocateElem_Sq(SqList L, int &i, ElemType x) {
    if (L.length == 0) return ERROR;
    // 返回元素在逻辑结构线性表里的位置
    ElemType *head = &(L.elem[0]), *p, *end = &(L.elem[L.length-1]);
    for (p=head; p<=end; p++) {
        if (*p == x) {
            i = (int)(++p-head);
            return TRUE;
        }
    }

    return FALSE;
}

Status DestroyList_Sq(SqList &L) {
    // 把分配的内存空间归还给系统
    free(L.elem);
    L.length = 0;
    L.listsize = 0;

    return OK;
}

Status ModList_Sq(SqList &L, int i, ElemType x) {
    // 判断修改位置是否合法
    if (i<1 || i>L.length) return ERROR;
    // 查找修改位置
    ElemType *q = &(L.elem[i-1]);
    *q = x;

    return OK;
}

Status PrintList_Sq(SqList L) {
    // 验证是否为空
    if (!L.elem) return ERROR;
    ElemType *p = &(L.elem[0]);
    for ( ; p<=&(L.elem[L.length-1]); p++)
        cout << *p << "\t";
    cout << endl;

    return OK;
}

// 线性表（部分）逆置
Status ReverseList_Sq(SqList &L, int LLeft, int LRight, int LLength) {
    // 表是否存在
    if (!L.elem) return ERROR;
    // 左右索引是否合法
    if (LRight-LLeft+1>LLength) return ERROR;

    int LMid = (LLeft + LRight) / 2;
    int i = 0;
    // 重点在于<=，不管LLeft+LRight是奇数还是偶数在这里都能够将中间两侧对调
    for (i = 0; i <= LMid; i++) {
      ElemType tmp = L.elem[i];
      L.elem[i] = L.elem[LRight - i];
      L.elem[LRight - i] = tmp;
    }

    return OK;
}

void Menu(SqList &L) {
    system("clear");
    cout << "操作菜单" << endl;
    cout << "1.初始化线性表" << endl;
    cout << "2.插入线性表" << endl;
    cout << "3.删除元素" << endl;
    cout << "4.定位元素" << endl;
    cout << "5.修改元素" << endl;
    cout << "6.逆置线性表" << endl;
    cout << "7.打印线性表" << endl;
    cout << "8.销毁线性表" << endl;
    cout << "9.退出" << endl;
    int cond;
    Status sta;
    cout << "请输入要进行的操作: ";
    cin >> cond;
    switch (cond) {
        case 1:
            if (InitList_Sq(L) == ERROR)
                cout << "创建失败" << endl;
            break;
        case 2:
            ElemType insert_elem;
            int insert_loc;
            cout << "请输入要插入的数字: ";
            cin >> insert_elem;
            cout << "请输入要插入的位置: ";
            cin >> insert_loc;
            sta = InsertList_Sq(L, insert_loc, insert_elem);
            if (sta == ERROR)
                cout << "线性表不存在或输入位置不合法" << endl;
            break;
        case 3:
            int del_loc;
            ElemType del_elem;
            cout << "请输入要删除的元素位置: ";
            cin >> del_loc;
            sta = ListDelete_Sq(L, del_loc, del_elem);
            if (sta == OK)
                cout << "删除元素的值为: " << del_elem << endl;
            else if (sta == ERROR)
                cout << "线性表不存在或输入位置不合法" << endl;
            else
                exit(-1);
            break;
        case 4:
            ElemType loc_elem;
            int locate_loc;
            cout << "请输入要定位元素的值: ";
            cin >> loc_elem;
            sta = LocateElem_Sq(L, locate_loc, loc_elem);
            if (sta == ERROR) {
                cout << "空表" << endl;
                break;
            } else if (sta == FALSE) {
                cout << "不存在的元素" << endl;
                break;
            }
            cout << "元素的位次是: " << locate_loc << endl;
            break;
        case 5:
            ElemType mod_elem;
            int mod_loc;
            cout << "请输入要修改的位置: ";
            cin >> mod_loc;
            cout << "请输入要修改的数字: ";
            cin >> mod_elem;
            sta = ModList_Sq(L, mod_loc, mod_elem);
            if (sta == ERROR)
                cout << "线性表不存在或输入位置不合法" << endl;
            break;
        case 6:
            sta = ReverseList_Sq(L, 0, L.length-1, L.length);
            if (sta == ERROR)
                cout << "线性表不存在" << endl;
            cout << "逆置后的线性表: " << endl;
            PrintList_Sq(L);
            break;
        case 7:
            sta = PrintList_Sq(L);
            if (sta==OK) {
                cout << "线性表元素个数: " << L.length << endl;
                cout << "线性表大小: " << L.listsize << endl;
            } else if (sta == ERROR)
                cout << "线性表不存在" << endl;
            break;
        case 8:
            DestroyList_Sq(L);
            break;
        case 9:
            system("clear");
            exit(0);
        default:
            cout << "错误的选项!" << endl;
            break;
    }
}
