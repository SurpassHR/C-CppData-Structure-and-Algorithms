#include "LinkStack.h"
#include <iostream>
using namespace std;

// 初始化链栈，栈底指针指向栈底元素的上一位，栈顶指针指向栈顶元素
Status MyLinkStack::InitStack() {
    st.top = st.bottom = (StackPtr)malloc(sizeof(StNode));
    if (!st.top) {
        return ERROR;
    }
    st.top->next = NULL;
    st.length = 0;

    return OK;
}

// 销毁链栈
Status MyLinkStack::DestroyStack() {
    while (st.bottom) {
        st.top = st.bottom->next;
        free(st.bottom);
        st.bottom = st.top;
    }

    return OK;
}

// 入栈
Status MyLinkStack::Push(ElemType val) {
    StackPtr ptr = (StackPtr)malloc(sizeof(StNode));
    if (!st.bottom || !ptr) {
        return ERROR;
    }
    ptr->data = val;
    ptr->next = NULL;
    st.top->next = ptr;
    st.top = ptr;

    return OK;
}

// 出栈
Status MyLinkStack::Pop(ElemType &e) {
    // 取得栈顶元素数据
    e = st.top->data;
    StackPtr p = st.bottom, q;

    // 得到栈顶指针的前一位
    while (p->next != st.top) {
        p = p->next;
    }

    // 临时存储栈顶指针
    q = st.top;

    // 断开连接
    p->next = NULL;

    // 释放空间
    free(q);

    // 新的栈顶指针
    st.top = p;

    return OK;
}

// 打印栈内元素
Status MyLinkStack::PrintStack() {
    StackPtr p = st.bottom;
    if (!p) {
        return ERROR;
    }

    while (p->next) {
        p = p->next;
        cout << p->data << "\t";
    }
    cout << endl;

    return OK;
}
