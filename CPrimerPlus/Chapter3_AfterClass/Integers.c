#include <stdio.h>
#include <stdint-gcc.h>

int main(void) {
    long int estine = 8;
    long johns = 8;
    printf("sizeof(long int) = %ld; sizeof(long) = %ld\n", sizeof(long int), sizeof(long));
    printf("long int == long: %s\n", estine == johns ? "TRUE" : "FALSE");
    printf("sizeof(int) = %ld; sizeof(long int) = %ld; sizeof(long long int) = %ld\n", sizeof(int), sizeof(long), sizeof(long long));

    // 在 16bit、32bit、64bit计算机中:
    // char 1bit, short 2bit
    // 但是c语言只规定了long的长度不小于int(long == long int),long long的长度不小于long
    /*
    平台/类型	char	short	int	    long	long long
    16位	    1	    2	    2	    4	    8
    32位	    1	    2	    4	    4	    8
    64位	    1	    2	    4	    8	    8
    */
    // 所以应该使用统一的规范长度的数据类型，包含在<stdint-gcc.h>中
    // 如(u)int8_t(int8_type)~(u)int64_t(int64_type)

    printf("sizeof(int8_t) = %ld; sizeof(int16_t) = %ld; sizeof(int32_t) = %ld; sizeof(int64_t) = %ld\n", sizeof(int8_t), sizeof(int16_t), sizeof(int32_t), sizeof(int64_t));

    return 0;
}
