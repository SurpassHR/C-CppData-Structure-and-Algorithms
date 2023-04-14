#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string S = "";
    getline(cin, S);
    istringstream iss(S);
    string word = "";
    int W = 0, count = 0;
    while (iss >> word) {
        W += word.size();
        count++;
    }
    // cout << W << " " << count << endl;
    printf("%.2lf\n", (double)W / count);
    return 0;
}