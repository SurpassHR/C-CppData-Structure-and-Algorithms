#include <iostream>
#include "SqList.h"
using namespace std;

int main() {
    SqList L;
    while (1) {
        Menu(L);
        getchar();
        cout << "Press any key to continue ...";
        getchar();
    }
    /*
    Status sta;
    ElemType elem_to_del;
    int elem_loc;
    SqList L;
    InitList_Sq(L);
    sta = InsertList_Sq(L, 1, 99);
    cout << "Status=" << sta << ", " << "Value=" << L.elem[0] << endl;
    sta = InsertList_Sq(L, 2, 128);
    cout << "Status=" << sta << ", " << "Value=" << L.elem[1] << endl;
    sta = ListDelete_Sq(L, 2, elem_to_del);
    cout << "Status=" << sta << ", " << "Value=" << L.elem[1] << endl;
    cout << "L.length=" << L.length << endl;
    cout << "Status=" << sta << ", " << "Value=" << L.elem[0] << endl;
    sta = LocateElem_Sq(L, elem_loc, 99);
    cout << "elem_loc=" << elem_loc << ", " << endl;
    PrintList_Sq(L);
    */
    return OK;
}
