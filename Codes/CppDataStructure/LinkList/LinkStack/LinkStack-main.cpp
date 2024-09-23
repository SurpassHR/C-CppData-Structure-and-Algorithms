#include "LinkStack.h"
#include <iostream>
using namespace std;

int main() {
    MyLinkStack st;
    ElemType e;
    st.InitStack();
    st.Push(4);
    st.PrintStack();
    st.Pop(e);
    cout << "弹出元素：" << e << endl;
    // st.Push(9);
    // st.PrintStack();

    return 0;
}
