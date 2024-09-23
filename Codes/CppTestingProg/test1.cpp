#include <bits/stdc++.h>

/* float types */
typedef float                  VOS_FLOAT;
typedef unsigned int           VOS_UINT32;
typedef int                    VOS_INT32;

union InvalidFloat {
    VOS_FLOAT f32Val;
    VOS_UINT32 u32Val;
};

#define EMAP_INVALID_VALUE_FLOAT 0xFFFFFFFF
#define INVALID_VALUE_FLOAT ((InvalidFloat){.u32Val = EMAP_INVALID_VALUE_FLOAT}).f32Val

union CtrlValType {
    VOS_INT32 signedVal;    // 有符号控制数据统一按I32处理
    VOS_UINT32 unsignedVal; // 无符号控制数据统一按U32处理（含控制值和枚举）。
    VOS_FLOAT f32Val;       // 浮点控制参数，如cft、cfh等
};

int main() {
    printf("%f\n", INVALID_VALUE_FLOAT);
    float f = EMAP_INVALID_VALUE_FLOAT;
    printf("%f\n", f);
    float ff = INVALID_VALUE_FLOAT;
    printf("%d\n", (int *)(&ff));
    printf("%f\n", ff);

    printf("%f-%f=%f\n", INVALID_VALUE_FLOAT, INVALID_VALUE_FLOAT, INVALID_VALUE_FLOAT-INVALID_VALUE_FLOAT);

    CtrlValType val{ 0 };
    printf("%u %d %f\n", val.unsignedVal, val.signedVal, val.f32Val);

    return 0;
}