#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    string input;
    while (getline(cin, input)) {
        istringstream iss(input);
        int tmp;
        while (iss >> tmp) {
            cout << tmp << endl;
            if (iss.get() == '\n') break;
        }
    }
    return 0;
}
