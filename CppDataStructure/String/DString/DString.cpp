/* 堆分配存储串实现 */
#include "DString.h"
#include <iostream>
using namespace std;

Status StrAssign(DString &T, char *chars) {
    int char_len = 0, i;
    char *ctemp = chars;

    // 字符串长
    while (ctemp && *ctemp != '\0') {
        ctemp++;
        char_len++;
    }

    // 分配空间
    T.ch = (char *)malloc(sizeof(char) * (char_len + 1));

    // 鲁棒性
    if (!T.ch) {
        return ERROR;
    }

    // 赋值
    ctemp = chars;
    for (i = 1; i <= char_len; i++) {
        T.ch[i] = *ctemp++;
    }
    T.ch[i] = '\0';
    T.length = char_len;

    return OK;
}

Status SubString(DString &Sub, DString S, int pos, int len) {
    int i = 1;
    if (pos > S.length || pos + len > S.length || !S.ch || !S.length) {
        return ERROR;
    }

    // 分配空间
    Sub.ch = (char *)malloc(sizeof(char) * (len + 1));
    if (!Sub.ch) {
        return ERROR;
    }

    // 赋值
    while (i <= len) {
        Sub.ch[i] = S.ch[pos + i - 1];
        i++;
    }
    Sub.length = len;

    return OK;
}

int StrCompare(DString S, DString T) {
    int i = 1;
    while (i <= S.length && i <= T.length) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        } else {
            i++;
        }
    }

    // 等长部分全相等，更长者更大
    return S.length - T.length;
}

Status StrPrint(DString T) {
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

int *GetNext(bool Optm, DString T) {
    // 计算 Next[]
    // 分配空间
    int *Next = (int *)malloc(sizeof(int) * (T.length + 1));

    if (!Next) {
        exit(-1);
    }

    // 自然赋值
    Next[1] = 0; Next[2] = 1;

    // 计算从 i = 3 开始
    int i = 3;

    // 最大比较子串长度
    int sub_len;

    // Next[] 赋值范围 [1:T.length]
    while (i <= T.length) {
        DString head_sub, tail_sub;
        // 从大到小比较可能的最大相同字串，sub_len 最大值 i - 2
        sub_len = i - 2;
        while (sub_len >= 0) {
            // 取得子串
            SubString(head_sub, T, 1, sub_len);
            SubString(tail_sub, T, i - sub_len, sub_len);

            // 串比较
            if (StrCompare(head_sub, tail_sub) == 0) {
                break;
            }

            // 缩短前后子串
            sub_len--;
        }
        Next[i++] = sub_len + 1;
    }

    // 计算 Nextval[]
    // 分配空间
    int *Nextval = (int *)malloc(sizeof(int) * (T.length + 1));
    if (!Nextval) {
        exit(-1);
    }

    // 自然赋值
    Nextval[1] = 0;

    // Nextval[] 赋值范围 [1:T.length]
    int j = 2;
    while (j <= T.length) {
        if (T.ch[j] == T.ch[Next[j]]) {
            Nextval[j] = Nextval[Next[j]];
        } else {
            Nextval[j] = Next[j];
        }
        j++;
    }

    if (Optm) {
        return  Nextval;
    } else {
        return Next;
    }
}

int Index_KMP(DString S, DString T, int Next[]) {
    int i = 1, j = 1;

    // 前说明匹配完毕，后说明成功匹配
    while (i <= S.length && j <= T.length) {
        // 首元素失配 或 当前元素匹配
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++; j++;
            // 当前元素失配 i 不变，j = Next[j]
        } else {
            i++;
            j = Next[j] + 1;
        }
    }

    // 循环完毕判断匹配情况
    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}
