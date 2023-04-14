#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    string input;
    multiset<string> str_v;
    while (getline(cin, input)) {
        string::iterator it = input.begin();
        string tmp_str = "";
        str_v = {};
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == ',') {
                str_v.emplace(tmp_str);
                tmp_str = "";
            } else {
                tmp_str.push_back(input[i]);
            }
        }
        str_v.emplace(tmp_str);
        // sort(str_v.begin(), str_v.end());
        auto set_it = str_v.begin();
        for (; set_it != str_v.end(); set_it++) {
            if (set_it != str_v.begin()) {
                cout << ",";
            }
            cout << *set_it;
        }
        cout << endl;
    }
    return 0;
}
