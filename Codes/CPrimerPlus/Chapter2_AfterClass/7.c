#include <stdio.h>

void smile(void) {
    printf("Smile!");

    return ;
}

void smile_with_newline(void) {
    printf("Smile!\n");

    return ;
}

int main(void) {
    smile();
    smile();
    smile_with_newline();
    smile();
    smile_with_newline();
    smile_with_newline();

    return 0;
}