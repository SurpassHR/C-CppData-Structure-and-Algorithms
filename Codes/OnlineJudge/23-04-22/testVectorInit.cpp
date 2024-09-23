#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a(100, 1);
    string A = "123";
    a.assign(A.begin(), A.end());
    a.insert(a.begin(), 100 - A.size(), 0);
    cout << a.size() << endl;
    for (int it : a) cout << it << " ";
    cout << endl;
    return 0;
}