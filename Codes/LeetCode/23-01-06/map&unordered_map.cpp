#include "../LeetCode.h"

int main() {
    map<int, int> m;
    multimap<int, int> mm;
    unordered_map<int, int> um;
    unordered_multimap<int, int> umm;
    m.emplace(1, 2);
    m.emplace(1, 3);
    mm.emplace(1, 2);
    mm.emplace(2, 2);
    mm.emplace(1, 3);
    um.emplace(1, 2);
    um.emplace(1, 3);
    umm.emplace(1, 2);
    umm.emplace(1, 3);



    cout << "m: " << endl;
    cout << "不允许重复键" << endl;
    for (auto it : m) {
        cout << "key: " << it.first << ", value: " << it.second << endl;
    }

    cout << "mm: " << endl;
    cout << "允许重复键，有序" << endl;
    for (auto it : mm) {
        cout << "key: " << it.first << ", value: " << it.second << endl;
    }

    cout << "um: " << endl;
    cout << "不允许重复键" << endl;
    for (auto it : um) {
        cout << "key: " << it.first << ", value: " << it.second << endl;
    }

    cout << "umm: " << endl;
    cout << "允许重复键，无序" << endl;
    for (auto it : umm) {
        cout << "key: " << it.first << ", value: " << it.second << endl;
    }

    // 取值
    cout << "取值: \n" << endl;
    cout << "map取值: " << endl;
    cout << "value(1) = " << m[1] << endl;

    cout << "multimap取值: " << endl;
    cout << "取得所有对应值的元素的迭代器:" << endl;
    auto itFind = mm.equal_range(1);
    auto upper = itFind.first;
    while (upper != itFind.second) {
        cout << upper->first << " " << upper->second << endl;
        upper++;
    }
    cout << endl;
}
