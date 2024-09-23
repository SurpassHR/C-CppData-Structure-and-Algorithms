#include "../../definition.h"

#ifndef _DSTRING_H_
#define _DSTRING_H_

// 堆分配顺序存储串结构声明
typedef struct {
    char *ch;
    int length;
} DString;

// 静态串赋值
Status StrAssign(DString &T, char *chars);
// 复制静态串
Status StrCopy(DString &T, DString S);
// 判断串空
Status StrEmpty(DString S);
// 打印串
Status StrPrint(DString S);
// 计算串长
int StrLength(DString S);
// 清空串
Status ClearString(DString &S);
// 销毁串
Status DestroyString(DString &S);
// 串连接 T = S1 + S2
Status Concat(DString &T, DString S1, DString S2);
// 求子串
Status SubString(DString &Sub, DString S, int pos, int len);
// 串大小比较（字典序）
int StrCompare(DString S, DString T);
// 朴素模式匹配算法
int Index(DString S, DString T);
// KMP算法
int *GetNext(bool Optm, DString T);
int Index_KMP(DString S, DString T, int next[]);

#endif
