//
// Created by h30045134 on 2024/9/23.
//

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> ptrA1 = make_shared<int>(10);
    shared_ptr<int> ptrA2(ptrA1);

    shared_ptr<int> ptrB1 = make_shared<int>(20);
    ptrA2 = ptrB1;

    // shared_ptr::use_count()计算的是当前持有该地址的指针的数目

    cout << ptrA1.use_count() << endl;
    cout << ptrB1.use_count() << endl;

    // 比较字典序
    string a = "abc";
    string b = "bc";
    string c = "bbc";
    cout << (a < b); // 1
    cout << (b < c) << endl; // 0

    // 若是直接比较 "abc" 与 "bc" 或 "bc" 与 "bbc"，则是比较地址，其实是一种未定义行为，无法知晓哪一个地址更大
    cout << ("abc" < "bc"); // &"abc" = 0x1a57d911700, &"bc" = 0x1a57d911740
    cout << ("bc" < "bbc"); // &"bbc" = 0x1a57d911780
    cout << ("bbc" < "bc");

    /*
     * (gdb) p 0x1a57d911700 < 0x1a57d911740
     * $5 = true
     * (gdb) p 0x1a57d911740 < 0x1a57d911780
     * $6 = true
     * (gdb) p 0x1a57d911780 < 0x1a57d911740
     * $7 = false
     * */

    return 0;
}