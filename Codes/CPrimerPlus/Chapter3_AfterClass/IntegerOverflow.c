#include <stdio.h>

void hextobin_rec(int hex) {
    // 使用递归实现的进制转换
    if (!hex) {
        return;
    }
    hextobin_rec(hex / 2);
    printf("%d", hex % 2);

    return;
}

struct stack {
    int *top, *bottom;
    int len;
    _Bool empty;
};

void hextobin(int hex) {
    // 使用栈实现的进制转换
    struct stack st;
    int arr[64];
    st.bottom = arr;
    st.top = &arr[0];
    st.len = 64;
    st.empty = 0;

    while (hex > 0) {
        *st.top = hex % 2;
        st.top += 1;
        hex /= 2;
    }

    while (st.top != st.bottom && !st.empty) {
        st.top -= 1;
        printf("%d", *st.top);
    }
    printf("\n");
}

int main(void) {
    int i = 2147483647;
    unsigned int j = 4294967295;

    printf("%d %d %d\n", i, i + 1, i + 2);
    printf("%u %u %u\n", j, j + 1, j + 2);

    hextobin_rec(i);
    printf("\n");
    hextobin_rec(j);
    printf("\n");

    printf("unsigned int 4294967295 = %u, signed int 4294967295 = %d\n", j, j);

    return 0;
}
