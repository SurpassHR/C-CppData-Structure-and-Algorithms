#include <bits/stdc++.h>
using namespace std;

int main() {
    int M;
    cin >> M;
    getchar();
    int tmp;
    vector<int> score, min_score;
    while (cin >> tmp) {
        score.push_back(tmp);
        if (cin.get() == '\n') break;
    }
    for (int i = 0; i < score.size() - M + 1; i++) {
        int mymin = score[i];
        for (int j = i + 1; j < i + M; j++) {
            mymin = min(mymin, score[j]);
        }
        min_score.push_back(mymin);
    }

    for (int i = 0; i < min_score.size(); i++) {
        if (i != 0) {
            cout << ",";
        }
        cout << min_score[i];
    }
    cout << endl;
    return 0;
}
