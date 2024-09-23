#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A()
    {
        printf("A constructor\n");
    }
    ~A()
    {
        printf("A Destructor\n");
    }
};

void *operator new(size_t size)
{
    if (size == 0) {
        return nullptr;
    }
    void *ptr = malloc(size);
    printf("alloc mem size[%zu], addr[%p]\n", size, ptr);
    return ptr;
}

void operator delete(void *ptr, size_t size)
{
    if (ptr == nullptr) {
        return;
    }
    printf("free mem size[%zu], addr[%p]\n", size, ptr);
    free(ptr);
}

A *CreateAFunc1()
{
    printf("CreateAFunc1\n");
    return new A;
}

A *CreateAFunc2()
{
    printf("CreateAFunc2\n");
    return new A;
}

using createAFunc = A *(*)();
createAFunc g_createAList[] = {
    CreateAFunc1,
    CreateAFunc2,
};

int main()
{
    A *a = new A;
    if (a != nullptr) {
        delete a;
    }
    for (int i = 0; i < sizeof(g_createAList) / sizeof(g_createAList[0]); ++i) {
        A *tmp = g_createAList[i]();
        delete tmp;
    }
    return 0;
}