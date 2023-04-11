#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str = "SOLO";
    vector<char> v;

    v.assign(str.begin(), str.end());
    for (char it : v) {
        cout << it << " ";
    }
    cout << endl;
}