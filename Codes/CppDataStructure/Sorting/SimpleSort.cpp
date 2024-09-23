/* 三种简单排序算法的CPP实现 */
#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubble_sort(int A[], int n) {
    int i, j;
    bool flag;
    for (i = 1; i < n; i++) {
        flag = false;
        for (j = n - 1; j >= i; j--) {
            if (A[j] < A[j - 1])
                Swap(A[j], A[j - 1]);
            flag = true;
        }
        if (!flag)
            return;
    }
}

void insertion_sort(int A[], int n) {
    int i, j;
    // int tmp;
    for (i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            // tmp = A[i];
            // for (j = i - 1; tmp < A[j] && j >= 0; j--)
            for (j = i - 1; A[j + 1] < A[j] && j >= 0; j--)
                Swap(A[j], A[j + 1]);
            // A[j + 1] = A[j];
            // A[j + 1] = tmp;
        }
    }
}

void selection_sort(int A[], int n) {
    int i, j, min;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                Swap(A[j], A[min]);
        }
    }
}

int main() {
    int A[5] = {33, 79, 12, 25, 7};
    int B[5] = {33, 79, 12, 25, 7};
    int C[5] = {33, 79, 12, 25, 7};
    int D[5] = {33, 79, 12, 25, 7};
    bubble_sort(A, 5);

    for (int i = 0; i < 5; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;

    insertion_sort(B, 5);
    for (int i = 0; i < 5; i++) {
        cout << B[i] << "\t";
    }
    cout << endl;

    selection_sort(C, 5);
    for (int i = 0; i < 5; i++) {
        cout << C[i] << "\t";
    }

    cout << endl;

    return 0;
}
