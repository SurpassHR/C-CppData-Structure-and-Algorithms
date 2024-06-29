#include <bits/stdc++.h>

class Test {
public:
    char a;
    short b;
    int c;
};

int main()
{
    Test t;
    printf("%p, %p, %p, %p\n", &t, &(t.a), &(t.b), &(t.c));
    printf("%d\n", &(t.b) - reinterpret_cast<short *>(&(t.a)) == sizeof(int));
    return 0;
}