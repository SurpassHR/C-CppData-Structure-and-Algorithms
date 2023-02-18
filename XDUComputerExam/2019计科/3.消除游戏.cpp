#include <stdio.h>
#include <string.h>

int main() {
    int m = 0, n = 0;
    scanf("%d%d", &m, &n);
    int a[m][n];
    int t[m][n];
    memset(a, 0, sizeof(a));
    memset(t, 0, sizeof(t));
    int i, j, k, l;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("原棋盘:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // 行遍历
    for (i = 0; i < m; i++) {
        for (j = 0, k = 1; j < n, k < n; k++) {
            if (a[i][j] == a[i][k]) {
                if (k - j + 1 >= 3) {
                    for (l = j; l < k + 1; l++) {
                        t[i][l] = 1;
                    }
                }
            } else {
                j++;
            }
        }
    }

    // 列遍历
    for (i = 0; i < n; i++) {
        for (j = 0, k = 1; j < m; k++) {
            if (a[j][i] == a[k][i]) {
                if (k - j + 1 >= 3) {
                    for (l = j; l < k + 1; l++) {
                        t[l][i] = 1;
                    }
                }
            } else {
                j++;
            }
        }
    }

    printf("消除棋盘:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    // 移动
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (t[i][j] == 1) {
                a[i][j] = 0;
            }
        }
    }

    printf("移动后棋盘:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
