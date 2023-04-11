#include <bits/stdc++.h>
using namespace std;
// int main() {
//     int num = 0;
//     vector<int> buf;
//     int cnt = 0;
//     while (cin >> num) {
//         for (int i = 1; i * i <= num; i++) {
//             if (num % i == 0) {
//                 buf.push_back(i);
//                 cnt++;
//                 if (i == num / i) {
//                 } else {
//                     buf.push_back(num / i);
//                     cnt++;
//                 }
//             }
//         }
//         sort(buf.begin(), buf.end());
//         cout << cnt;
//         for (int i = 0; i < cnt; i++) {
//             cout << " " << buf[i];
//         }
//         cout << endl;
//     }
//     return 0;
// }

int main() {
    int N = 0;
    cin >> N;
    vector<int> buf = {};
    // 分支优化
    if (N == 1) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    // 判断是否能够被该数整除
    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            buf.push_back(i);
            // 优化：如果该数是因数那么N除以该数所得也一定是N的因数
            if (i != N / i)
                buf.push_back(N / i);
        }
    }
    // 从小到大排序
    sort(buf.begin(), buf.end());
    cout << buf.size();
    for (int it : buf) {
        cout << " " << it;
    }
    cout << "\n";
    return 0;
}