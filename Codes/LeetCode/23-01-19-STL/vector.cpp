#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> list; // vector<int> list(100);
    list.push_back(1);
    list.push_back(5);
    cout << "按下标遍历vector:" << endl;
    for (int i = 0; i < list.size(); i++) cout << list[i] << " ";
    cout << endl;
    cout << "迭代器遍历vector:" << endl;
    for (vector<int>::iterator it = list.begin(); it != list.end(); it++) cout << (*it) << " ";
    cout << endl;
    cout << "基本范围的for循环遍历vector:" << endl;
    for (int i : list) cout << i << " ";
    cout << endl;

    cout << "指针与迭代器的区别:" << endl;
    vector<int>::iterator it = list.begin();
    int* p = &list[0];
    printf("add of it: %p, add of p: %p\n", it, p);

    return 0;
}
