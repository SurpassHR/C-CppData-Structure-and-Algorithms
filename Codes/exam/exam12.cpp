#include<iostream>
#include<string>
using namespace std;
int main() {
    string a = "Huawei";
    const char* b = a.c_str();

    cout << a << endl;
    cout << b << endl;

    a += string(100, '1');
    cout << a << endl;
    cout << b << endl;
    return 0;
}