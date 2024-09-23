#include <iostream>
#include <vector>
using namespace std;

string singleMult(string A, char c) {
    string singleQuo;
    int carry = 0, val = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        val = (A[i] - '0') * (c - '0') + carry;
        carry = val / 10;
        val %= 10;
        singleQuo.insert(singleQuo.begin(), val + '0');
    }
    singleQuo.insert(singleQuo.begin(), carry + '0');
    auto it = singleQuo.begin();
    while (*it == '0') singleQuo.erase(it);

    return singleQuo;
}

void singleAdd(string& sum, string addition) {
    int val = 0, carry = 0;
    int len = max(sum.size(), addition.size());
    vector<int> a, b;
    a.assign(sum.begin(), sum.end());
    b.assign(addition.begin(), addition.end());
    for (auto it = a.begin(); it != a.end(); it++) *it -= '0';
    for (auto it = b.begin(); it != b.end(); it++) *it -= '0';
    a.insert(a.begin(), len - a.size(), 0);
    b.insert(b.begin(), len - b.size(), 0);
    string res;
    for (int i = len - 1; i >= 0; i--) {
        val = a[i] + b[i] + carry;
        carry = val / 10;
        val %= 10;
        res.insert(res.begin(), val + '0');
    }
    res.insert(res.begin(), carry + '0');
    auto it = res.begin();
    while (*it == '0') res.erase(it);
    sum = res;
}

void multiply(string& A, string B) {
    string sum;
    if (A == "0" || B == "0") {
        A = "0";
    }
    vector<string> tmp;
    for (int i = B.size() - 1; i >= 0; i--) {
        tmp.push_back(singleMult(A, B[i]));
    }
    sum = tmp[0];
    for (int i = 1; i < tmp.size(); i++) {
        tmp[i].insert(tmp[i].end(), i, '0');
        singleAdd(sum, tmp[i]);
    }
    A = sum;
}

int main() {
    int N = 0;
    string quotient = "1";
    while (cin >> N) {
        if (N == 0) {
            cout << "1" << endl;
            continue;
        }
        // factorial
        for (int i = 2; i <= N; i++) {
            multiply(quotient, to_string(i));
        }
        cout << quotient << endl;
    }

    return 0;
}
