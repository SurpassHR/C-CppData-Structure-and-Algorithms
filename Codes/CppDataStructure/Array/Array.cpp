#include "Array.h"
#include <iostream>
using namespace std;

void Init2DArr(ElemType **arr, int rows, int cols) {
    ElemType **row = arr;
    ElemType *col = *row;
    int row_cnt = 0;
    int col_cnt = 0;

    *col = 99;

    while (row_cnt < rows) {
        while (col_cnt < cols) {
            *col = (col_cnt + 1) * (row_cnt + 1);
            col_cnt++;
            col++;
        }
        row_cnt++;
        row++;
        col = *row;
        col_cnt = 0;
    }

    return;
}

void Print2DArr(ElemType **arr, int rows, int cols) {
    ElemType **row = arr;
    ElemType *col = *row;
    int row_cnt = 0;
    int col_cnt = 0;

    *col = 99;

    while (row_cnt < rows) {
        while (col_cnt < cols) {
            cout << *col << " ";
            col_cnt++;
            col++;
        }
        cout << endl;
        row_cnt++;
        row++;
        col = *row;
        col_cnt = 0;
    }

    return;
}


int main() {
    cout << "-----第一种数组创建方式-----" << endl;
    int rows = 5, cols = 4;
    ElemType array1[rows][cols];
    cout << "sizeof(array1) = " << sizeof(array1) / sizeof(array1[0]) << ", sizeof(array1[0]) = " << sizeof(array1[0]) / sizeof(ElemType) << endl;
    cout << array1 << " " << array1[1] << " " << *(array1 + 2) << endl;
    ElemType *p[rows] = { array1[0], array1[1], array1[2], array1[3], array1[4] };
    Init2DArr(p, rows, cols);
    Print2DArr(p, rows, cols);
    cout << "-----第二种数组创建方式-----" << endl;
    ColArr array2[cols];
    ElemType *p1[rows] = { array2[0], array2[1], array2[2], array2[3], array2[4] };
    Init2DArr(p1, rows, cols);
    Print2DArr(p1, rows, cols);
    cout << "-----第三种数组创建方式-----" << endl;
    TwoDArr array3;
    ElemType *p2[rows] = { array3[0], array3[1], array3[2], array3[3], array3[4] };
    Init2DArr(p2, rows, cols);
    Print2DArr(p2, rows, cols);
    return 0;
}
