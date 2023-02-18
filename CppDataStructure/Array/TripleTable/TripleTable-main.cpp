#include "TripleTable.h"
#include <iostream>
using namespace std;

int main() {
    TripleTable t;
    ElemType vals[] = {0, 12, 9, -3, 14, 24, 18, 15, -7};
    int rows = 6, cols = 7;
    int num = sizeof(vals) / sizeof(vals[0]) - 1;
    int pos[num + 1][2] = {{0, 0}, {1, 2}, {1, 3}, {3, 1}, {3, 6}, {4, 3}, {5, 2}, {6, 1}, {6, 4}};
    int *p[num + 1];
    for (int i = 1; i <= num; i++) {
        p[i] = pos[i];
    }

    TripleTable tT;
    ElemType valsT[1] = {0};
    int rowsT = cols, colsT = rows;
    int numT = 0;
    int **posT;

    CreateTripleTable(t, num, vals, p, rows, cols);
    CreateTripleTable(tT, numT, valsT, posT, rowsT, colsT);
    PrintTripleTable(t);
    PrintTripleTable(tT);
    TransMatrix(t, tT);
    PrintTripleTable(tT);

    return 0;
}
