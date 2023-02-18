#include "../../definition.h"

#ifndef _TRIPLETABLE_H_
#define _TRIPLETABLE_H_

#define MAXSIZE 1000

typedef int ElemType;
typedef struct
{
    ElemType val;
    int row, col;
} Triple;
typedef struct
{
    Triple data[MAXSIZE];
    int rows, cols, num;
} TripleTable;

Status CreateTripleTable(TripleTable &t, int num, ElemType vals[], int **pos, int rows, int cols);
Status PrintTripleTable(TripleTable t);
Status TransMatrix(TripleTable t, TripleTable &tT);
bool InTable(TripleTable t, int posRow, int posCol, ElemType &e);

#endif
