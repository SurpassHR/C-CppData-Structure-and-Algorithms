#ifndef _JOSEPHCIRCLE_CL_H_
#define _JOSEPHCIRCLE_CL_H_

#ifndef _CL_DEF_
#define _CL_DEF_

typedef struct LNode {
    int No;  // 玩家的位序
    unsigned int Pwd;  // 玩家手持的密码
    struct LNode *next;
} LNode, *LinkList;

#endif

#include "../CircularLinkList.h"

void PlayGame_s1(LinkList &L, int number, int init_pwd);
void PlayGame_s2(LinkList &L, int number, int pwd);

#endif
