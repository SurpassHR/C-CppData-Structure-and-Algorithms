#include <iostream>

using namespace std;

string func(int n) {
    if (n == 1) {
        return "NO";
    }
    if (n % 2 != 0) {
        return "YES";
    }
    return func(n / 2);
}

int main() {
    int n = 0;
    cin >> n;
    cout << func(n);
}


// #include "stdio.h"
// #include "stdlib.h"

// int main() {
//     int u32_input, u32_thre, u32_first, u32_last, u32_temp;
//     int i = 1, j, k = 0;

//     printf("please input the number !\n");
//     scanf("%d", &u32_input);
//     u32_thre = u32_input / 2 + 1;
//     while (i < u32_thre) {
//         u32_first = i;
//         u32_temp = u32_input;
//         j = i;
//         while (u32_temp > 0)
//         {
//             u32_temp -= j;
//             u32_last = j;
//             j++;
//         }
//         if (u32_temp == 0)
//         {
//             while (u32_first <= u32_last)
//             {
//                 printf("%d \t", u32_first);
//                 u32_first++;
//             }
//             printf("\n");
//             k = 1;
//         }
//         i++;
//     }
//     if (k == 0)
//     {
//         printf("None!\n");
//     }
//     return 0;
// }