#include <iostream>
using namespace std;

#define VOS_VOID void

#define VOS_UINT64 unsigned long int
#define VOS_INT64 long int
#define VOS_UINT32 unsigned int
#define VOS_INT32 int
#define VOS_UINT16 unsigned short
#define VOS_INT16 short
#define VOS_UINT8 char

VOS_VOID Func(VOS_INT32 value) {
    return;
}

int main() {
    VOS_INT16 i16Value = 0;
    VOS_INT64 i64Value = 0;

    Func(i16Value);
    Func(i64Value);

    return 0;
}
