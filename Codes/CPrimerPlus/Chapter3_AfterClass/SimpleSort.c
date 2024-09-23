/* 三种简单排序算法 */
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int len);
void selection_sort(int arr[], int len);
void insertion_sort(int arr[], int len);
void swap(int *a, int *b);

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}

void bubble_sort(int arr[], int len) {
    int i, j, flag;

    // 循环次数
    for (i = 0; i < len; i++) {
        flag = 0;

        // 无序部分冒泡
        for (j = len - 1; j > i; j--)
            if (arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
                flag = 1;
            }

        // 序列有序
        if (!flag)
            return;
    }

    return;
}

void selection_sort(int arr[], int len) {
    int i, j, min;

    // 假定前 i 个元素已有序
    for (i = 0; i < len; i++) {
        // 假定无序部分第一个为最小
        min = i;

        // 遍历找最小值
        for (j = i; j < len; j++)
            if (arr[j] < arr[min])
                min = j;

        // 最小不是无序序列第一个
        if (min != i)
            swap(&arr[min], &arr[i]);
    }

    return;
}

void insertion_sort(int arr[], int len) {
    int i, j, cur;

    // 当前有序序列长度为 i
    for (i = 1; i < len; i++) {
        // 保存无序序列第一个元素
        cur = arr[i];

        // 在有序序列中找到合适的插入位置
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > cur)
                arr[j + 1] = arr[j];
            else
                break;
        }

        // 插入到空缺位置
        arr[j + 1] = cur;
    }

    return;
}

int *copy_array(int a[], int len) {
    int *b = (int *)malloc(sizeof(int) * len);
    int i;
    for (i = 0; i < len; i++) {
        b[i] = a[i];
    }

    return b;
}

void newline(void) {
    puts("\n");

    return;
}

void print_array(int a[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    newline();

    return;
}

int main(void) {
    int len = 6;
    int a[6] = {23, 12, 34, 9, 12, 20};
    int *b = copy_array(a, len);
    int *c = copy_array(a, len);

    // 打印数组
    printf("array a:\n");
    print_array(a, len);
    printf("array b:\n");
    print_array(b, len);
    printf("array c:\n");
    print_array(c, len);

    // 冒泡排序
    bubble_sort(a, len);
    printf("sorted array a:\n");
    print_array(a, len);

    // 简单选择排序
    selection_sort(b, len);
    printf("sorted array b:\n");
    print_array(b, len);

    // 直接插入排序
    insertion_sort(c, len);
    printf("sorted array c:\n");
    print_array(c, len);

    return 0;
}
