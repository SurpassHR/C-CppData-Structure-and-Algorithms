#include <iostream>
using namespace std;

int main() {
    string hex = "";
    int sum = 0;
    cin >> hex;
    for (int i = 2; i < hex.size(); i++) {
        sum *= 16;
        if (hex[i] >= 'A' && hex[i] <= 'F') sum += hex[i] - 'A' + 10;
        else sum += hex[i] - '0';
    }
    cout << sum << endl;
}
