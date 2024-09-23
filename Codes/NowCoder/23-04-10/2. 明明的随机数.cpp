#include <iostream>
using namespace std;

int main() {
    int t, N;
    cin >> N;
    int a[500] = { 0 };
    for (int i = 0; i < N && cin >> t; i++) a[t]++;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) if (a[i]) printf("%d\n", i);
    return 0;
}
