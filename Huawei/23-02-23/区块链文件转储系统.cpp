#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j;
    int M;
    string input;
    cin >> M;
    getchar();
    getline(cin, input);
    istringstream iss(input);
    vector<int> file_size;
    int fs;
    while (iss >> fs) {
        file_size.push_back(fs);
    }
    int sum, mymax = 0;
    for (i = 0; i < file_size.size(); i++) {
        sum = 0;
        for (j = i; j < file_size.size(); j++) {
            sum += file_size[j];
            if (sum <= M) {
                mymax = max(mymax, sum);
            } else {
                break;
            }
        }
    }
    cout << mymax << endl;
    return 0;
}
