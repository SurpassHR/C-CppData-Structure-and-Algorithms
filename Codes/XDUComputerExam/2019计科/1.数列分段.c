#include <stdio.h>

int main() {
    int n, i, before, curr;
    int count = 1;
    scanf("%d", &n);
    scanf("%d", &before);
    for (i = 1; i < n; i++) {
        scanf("%d", &curr);
        if (curr != before) {
            count += 1;
        }
        before = curr;
    }
    printf("%d\n", count);

    return 0;
}
