#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int a;
    a = 0x11121314;
    printf("%d \t\n", a);
    printf("0x%X \t\n", a);
    long l;
    l = 0x3ff3333333333333;
    printf("%lf\n", *(double *)&l);
    return 0;
}
