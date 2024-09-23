#include <iostream>
#include <vector>
using namespace std;

string multiply(string A, string B) {
    if (A == "0" || B == "0") {
        return "0";
    }
    string ret;
    int len1 = A.size(), len2 = B.size();
    vector<int> res(len1 + len2, 0);
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int val = (A[i] - '0') * (B[j] - '0') + res[i + j + 1];
            res[i + j + 1] = val % 10;
            res[i + j] += val / 10;
        }
    }
    for (auto digit : res) {
        ret.push_back(digit + '0');
    }
    while (ret.size() > 1 && ret[0] == '0') {
        ret.erase(ret.begin());
    }

    return ret;
}

int main() {
    int N = 0;
    string quotient = "1";
    while (cin >> N) {
        if (N == 0) {
            cout << "1" << endl;
            continue;
        }
        for (int i = 2; i <= N; i++) {
            quotient = multiply(quotient, to_string(i));
        }
        cout << quotient << endl;
    }

    return 0;
}
