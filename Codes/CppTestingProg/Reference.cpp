#include <iostream>
#include <utility>
using namespace std;

int main() {
    int a = 42;

    int& lvalueRef = a; // 左值引用绑定到左值 a
    int&& rvalueRef = std::move(a); // 右值引用绑定到右值 a

    cout << "Before modification:" << endl;
    cout << "a = " << a << endl; // 输出原始 a 的值
    cout << "lvalueRef = " << lvalueRef << endl; // 输出左值引用的值
    cout << "rvalueRef = " << rvalueRef << endl; // 输出右值引用的值

    lvalueRef = 10; // 修改左值引用的值

    cout << "After modification:" << endl;
    cout << "a = " << a << endl; // 输出修改后的 a 的值
    cout << "lvalueRef = " << lvalueRef << endl; // 输出左值引用的值
    cout << "rvalueRef = " << rvalueRef << endl; // 输出右值引用的值

    return 0;
}
