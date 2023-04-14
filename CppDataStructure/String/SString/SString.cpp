/* 定长（静态）顺序存储串实现 */
#include "SString.h"
#include <iostream>
using namespace std;

Status StrAssign(SString &T, char *chars) {
    int i;
    char *ctemp = chars;
    int char_len = 0;

    // 判断字符串是否超过串空间大小
    while (ctemp && *ctemp != '\0') {
        ctemp++;
        char_len++;
        if (char_len > MAXLENGTH - 1) {
            return ERROR;
        }
    }

    // 串长置零，重新赋值
    ctemp = chars;
    for (i = 1; i <= char_len; i++) {
        T.ch[i] = *ctemp++;
    }
    T.length = char_len;
    T.ch[i + 1] = '\0';

    return OK;
}

Status StrPrint(SString T) {
    char *chtemp = T.ch;
    int i;

    // 判断串空
    if (!T.ch && !T.length) {
        return ERROR;
    }

    // 打印
    for (i = 1; i <= T.length; i++) {
        cout << T.ch[i];
    }
    cout << endl;

    return OK;
}

int StrCompare(SString S, SString T) {
    int i;

    // 逐位比较 ASCII 值
    for (i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }

    // 有效位都相同则较长者大
    return S.length - T.length;
}

Status SubString(SString &Sub, SString S, int pos, int len) {
    char *stemp = (char *)malloc(len * sizeof(char));
    char *p = stemp;
    int i;

    // 判断合法性
    if (pos > S.length || pos + len > S.length || !S.ch || !S.length) {
        return ERROR;
    }

    // 提取子串
    for (i = pos; i < pos + len; i++) {
        *p++ = S.ch[i];
    }
    *p = '\0';

    // 赋值
    StrAssign(Sub, stemp);

    return OK;
}

int Index(SString S, SString T) {
    int i, j;
    for (i = 1; i <= S.length; i++) {
        // 子串比较
        for (j = 1; j <= T.length; j++) {
            if (S.ch[i + j - 1] != T.ch[j]) {
                break;
            }
        }
        if (j > T.length) {
            return i;
        }
    }

    return 0;
}

int Index(int _, SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        // 相同则继续匹配，否则主串指针复位+2
        if (S.ch[i] == T.ch[j]) {
            i++; j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}

int Index_Improved(SString S, SString T) {
    int i = 1;
    SString Sub;

    // 取出相同长度的子串与模式串匹配，直到 T.length - S.length + 1
    while (i + T.length <= S.length) {
        SubString(Sub, S, i, T.length);
        if (StrCompare(T, Sub) != 0) {
            i++;
        } else {
            return i;
        }
    }

    return 0;
}

int *GetNext(SString T) {
    int *Next = (int *)malloc(sizeof(int) * (T.length + 1));

    // 鲁棒性
    if (!Next) {
        exit(-1);
    }

    int i = 3, sub_len;
    SString head_sub, tail_sub;
    Next[1] = 0; Next[2] = 1;

    // 求 Next[]
    while (i <= T.length) {
        sub_len = i - 2;
        while (sub_len >= 0) {
            SubString(head_sub, T, 1, sub_len);
            SubString(tail_sub, T, i - sub_len, sub_len);
            if (StrCompare(head_sub, tail_sub) == 0) {
                break;
            }
            sub_len--;
        }
        Next[i++] = sub_len + 1;
    }

    return Next;
}

int *GetNextval(SString T) {
    int *Next = (int *)malloc(sizeof(int) * (T.length + 1));

    // 鲁棒性
    if (!Next) {
        exit(-1);
    }

    // 空出下标 0 方便计算，默认值 1, 2
    Next[1] = 0; Next[2] = 1;
    int i = 3;
    int sub_len;

    // 计算 Next[]

    while (i <= T.length + 1) {
        sub_len = i - 2;
        while (sub_len >= 0) {
            SString head_sub, tail_sub;
            SubString(head_sub, T, 1, sub_len);
            SubString(tail_sub, T, i - sub_len, sub_len);
            if (StrCompare(head_sub, tail_sub) == 0) {
                break;
            }
            sub_len--;
        }
        Next[i++] = sub_len + 1;
    }

    int *Nextval = (int *)malloc(sizeof(int) * (T.length + 1));

    // 鲁棒性
    if (!Nextval) {
        exit(-1);
    }

    // 计算 Nextval[]
    Nextval[1] = 0;
    int j = 2;
    while (j <= T.length) {
        if (T.ch[j] != T.ch[Next[j]]) {
            Nextval[j] = Next[j];
        } else {
            Nextval[j] = Nextval[Next[j]];
        }
        j++;
    }

    return Nextval;
}

int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++; j++;
        } else {
            // 相比仅使用 j = next[j]; 减少一次比较相同的时间
            i++;
            j = next[j] + 1;
        }
    }

    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}
