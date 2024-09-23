#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, int> mmap;
    mmap.insert({1, 1});
    mmap.insert({1, 2});
    mmap.insert({1, 3});
    auto itFind = mmap.equal_range(1);
    auto upper = itFind.first;
    cout << upper->first << endl;
    cout << upper->second << endl;
    auto lower = itFind.second;
    cout << lower->first << endl;
    cout << lower->second << endl;
    return 0;
}