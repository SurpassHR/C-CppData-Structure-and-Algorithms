#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    int t;
    vector<int> trees;
    while (cin >> t) {
        if (cin.get() == '\n') break;
        trees.push_back(t);
    }
    int p, q;
    while (cin >> p >> q) {
        int myMax = 0, myMin = INT32_MAX;
        for (int i = p - 1; i < q; i++) {
            myMax = max(myMax, trees[i]);
            myMin = min(myMin, trees[i]);
        }
        cout << myMax - myMin << endl;
        Q--;
        if (Q == 0) break;
    }
    return 0;
}
