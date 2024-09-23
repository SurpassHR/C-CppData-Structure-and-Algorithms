#include <stdio.h>

int main(void) {
    char grade;
    printf("sizeof(char) = %ld\n", sizeof(char));

    // 将一个32bit字符常量赋值给8bit的char类型，编译器出现warning，输出时为'E'，ASCII值为69
    grade = 'FATE';
    printf("grade = %c = %d\n", grade, grade);

    return 0;
}
