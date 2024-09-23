#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<bool>> t;
    t.resize(3, vector<bool>(4));
    for (auto it1 : t) {
        for (auto it2 : it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }
    /**
     * out:
     * 0 0 0 0
     * 0 0 0 0
     * 0 0 0 0
    */
    return 0;
}