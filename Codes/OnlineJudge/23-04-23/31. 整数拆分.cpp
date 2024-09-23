#include <iostream>
using namespace std;

int resultCnt = 0;

void calcResultCnt(int N) {
    for (int i = 1; i <= N; i++) {
        if (N == i) {
            resultCnt++;
            return;
        } else if (N > i) {
            calcResultCnt(N - i);
        } else {
            return;
        }
    }
}

int main() {
    int N = 0;
    while (cin >> N) {
        resultCnt = 0;
        if (N < 1 || N > 120) {
            return -1;
        }
        calcResultCnt(N);
        cout << resultCnt << endl;
    }
    return 0;
}