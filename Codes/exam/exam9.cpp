#include "stdio.h"
void PrintLen(char szStr[3]) {
    printf("%d\n", sizeof(szStr));
    return;
}
int main() {
    char szStr[] = "hello";
    PrintLen(szStr);

    return 0;
}