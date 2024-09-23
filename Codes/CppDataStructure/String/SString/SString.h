#include "../../definition.h"

#ifndef _SSTRING_H_
#define _SSTRING_H_

#define MAXLENGTH 255
// 定长顺序存储串结构声明，其中 ch[0] 为空
typedef struct SString_Node {
    char ch[MAXLENGTH];
    int length;
} SString;

// 静态串赋值
Status StrAssign(SString &T, char *chars);
// 复制静态串
Status StrCopy(SString &T, SString S);
// 判断串空
Status StrEmpty(SString S);
// 打印串
Status StrPrint(SString S);
// 计算串长
int StrLength(SString S);
// 清空串
Status ClearString(SString &S);
// 销毁串
Status DestroyString(SString &S);
// 串连接 T = S1 + S2
Status Concat(SString &T, SString S1, SString S2);
// 求子串
Status SubString(SString &Sub, SString S, int pos, int len);
// 串大小比较（字典序）
int StrCompare(SString S, SString T);
// 不借助函数朴素模式匹配算法
int Index(SString S, SString T);
int Index(int _, SString S, SString T);
// 借助函数的朴素模式匹配算法
int Index_Improved(SString S, SString T);
// KMP算法
int *GetNext(SString T);
int *GetNextval(SString T);
int Index_KMP(SString S, SString T, int next[]);

#endif
