#include <stdio.h>

void br(void) {
    printf("Brazil, Russia");

    return ;
}

void ic(void) {
    printf("India, China");

    return ;
}

int main(void) {
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf("\n");
    br();
    printf("\n");

    return 0;
}