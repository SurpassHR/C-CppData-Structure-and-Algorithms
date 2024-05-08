#include <iostream>

void f1(char* p) {
    char s[] = "const";

    const char* p1 = s;
    p1[3] = 'g';

    char* const p2 = s;
    p2[3] = 'g';

    const char const* p3 = s;
    p3[3] = 'g';
}