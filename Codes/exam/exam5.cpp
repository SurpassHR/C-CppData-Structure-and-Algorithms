#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
    map<string, int> dict;
    dict.insert(std::make_pair("bcdefg", 2));
    dict.insert(std::make_pair("abcdefg", 3));
    dict.insert(std::make_pair("cdefg", 1));
    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        cout << iter->first << ", " << iter->second << endl;
    }
    return 0;
}