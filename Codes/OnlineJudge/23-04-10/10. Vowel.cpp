#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    string s = "";
    string input = "";
    map<char, int> vowelTab = {
        {'a', 1},
        {'e', 1},
        {'i', 1},
        {'o', 1},
        {'u', 1},
        {'A', 1},
        {'E', 1},
        {'I', 1},
        {'O', 1},
        {'U', 1}
    };
    getline(cin, input);
    istringstream iss(input);
    bool first = 1;
    while (iss >> s) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 97 && s[i] <= 122) if (vowelTab[s[i]]) s[i] -= 32;
            else if (!vowelTab[s[i]]) s[i] += 32;
        }
        cout << s;
        if (iss.get() == '\n') break;
    }
    return 0;
}