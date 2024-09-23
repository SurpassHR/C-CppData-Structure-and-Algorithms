#include <stdio.h>

int main(void) {
    int x = 100;

    // %d,%o,%x 被称为占位符 (format specifier) 或 转换说明 (convertion specifier)
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    // 八进制为0开头，十六进制为0x开头
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

    return 0;
}
