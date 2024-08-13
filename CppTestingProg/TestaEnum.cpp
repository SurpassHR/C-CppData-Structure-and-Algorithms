#include <bits/stdc++.h>
using namespace std;

enum AutoDetectResult : unsigned short {
    AUTO_DETECT_INIT = 0,  // 自动诊断开始前初始化所有部件的自检结果
    AUTO_DETECT_SUCCESS,  // 自动诊断成功
    AUTO_DETECT_FAIL,  // 本逻辑组能力不达标
    AUTO_DETECT_ABORT,  // 其他逻辑组故障引起的自动诊断中止
    AUTO_DETECT_FAULT,  // 本逻辑组故障
    AUTO_DETECT_INVALID,
};

int main()
{
    unsigned short a = 5;
    printf("%u\n", (a == AutoDetectResult::AUTO_DETECT_INVALID));
    return 0;
}