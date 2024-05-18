#include <bits/stdc++.h>

/* float types */
typedef float                  VOS_FLOAT;
typedef unsigned int           VOS_UINT32;

union InvalidFloat {
    VOS_FLOAT f32Val;
    VOS_UINT32 u32Val;
};

#define EMAP_INVALID_VALUE_FLOAT 0xFFFFFFFF
#define INVALID_VALUE_FLOAT ((InvalidFloat){.u32Val = EMAP_INVALID_VALUE_FLOAT}).f32Val

int main() {
    printf("%f\n", INVALID_VALUE_FLOAT);
    float f = EMAP_INVALID_VALUE_FLOAT;
    printf("%f\n", f);
    return 0;
}