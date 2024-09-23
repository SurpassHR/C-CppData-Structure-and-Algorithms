#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mysort(pair<string, vector<int>> c1, pair<string, vector<int>> c2) {
    // 金牌数比较
    if (c1.second[0] > c2.second[0]) {
        return true;
    } else if (c1.second[0] < c2.second[0]) {
        return false;
    } else {
        // 银牌数比较
        if (c1.second[1] > c2.second[1]) {
            return true;
        } else if (c1.second[1] < c2.second[1]) {
            return false;
        } else {
            // 铜牌数比较
            if (c1.second[2] > c2.second[2]) {
                return true;
            } else if (c1.second[2] < c2.second[2]) {
                return false;
            } else {
                // 国家字典序比较
                if (c1.first.compare(c2.first) < 0) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

int main() {
    int N, Gi, Si, Bi;
    string country;
    cin >> N;
    vector<pair<string, vector<int>>> medals;
    for (int i = 0; i < N && cin >> country >> Gi >> Si >> Bi; i++) medals.push_back({ country, {Gi, Si, Bi} });
    // 排序
    sort(medals.begin(), medals.end(), mysort);
    for (auto pair : medals) cout << pair.first << endl;
    return 0;
}