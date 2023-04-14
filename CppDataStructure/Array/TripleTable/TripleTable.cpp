#include "TripleTable.h"
#include <iostream>
using namespace std;

Status CreateTripleTable(TripleTable &t, int num, ElemType vals[], int **pos, int rows, int cols) {
    for (int i = 1; i <= num; i++) {
        t.data[i].row = *(*(pos + i) + 0);
        t.data[i].col = *(*(pos + i) + 1);
        t.data[i].val = *(vals + i);
    }

    t.rows = rows;
    t.cols = cols;
    t.num = num;
    return OK;
}

Status PrintTripleTable(TripleTable t) {
    int i;
    for (int row = 1; row <= t.rows; row++) {
        for (int col = 1; col <= t.cols; col++) {
            for (i = 1; i <= t.num; i++) {
                if (t.data[i].row == row && t.data[i].col == col) {
                    break;
                }
            }
            if (i > t.num) {
                cout << 0 << "\t";
            } else {
                cout << t.data[i].val << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;

    return OK;
}

bool InTable(TripleTable t, int posRow, int posCol, ElemType &e);

Status TransMatrix(TripleTable t, TripleTable &tT) {
    int num_of_each_col[t.cols + 1] = {0};
    int idx_of_each_first[t.cols + 1] = {1};

    for (int col = 1; col <= t.cols; col++) {
        idx_of_each_first[col] = 1;
    }

    for (int i = 1; i <= t.num; i++) {
        tT.data[i].row = t.data[i].col;
        tT.data[i].col = t.data[i].row;
        tT.data[i].val = t.data[i].val;
        tT.num++;
    }

    // Get elem num of each column of original matrix
    for (int i = 1; i <= t.num; i++) {
        num_of_each_col[t.data[i].col]++;
    }

    // Get first elem's index of each col
    for (int col = 2; col <= t.cols; col++) {
        idx_of_each_first[col] = num_of_each_col[col - 1] + idx_of_each_first[col - 1];
    }

    // Output test
    for (int col = 1; col <= t.cols; col++) {
        cout << idx_of_each_first[col] << "\t";
    }
    cout << endl;
    cout << endl;

    for (int i = 1; i <= t.num; i++) {
        int row = tT.data[i].row;
        int iT = idx_of_each_first[row];

        // Swap
        Triple tri = tT.data[iT];
        tT.data[iT] = tT.data[i];
        tT.data[i] = tri;

        idx_of_each_first[row]++;
    }

    return OK;
}
