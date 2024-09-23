#include "DString.h"
#include <iostream>
using namespace std;

int main() {
    cout << "-----取子串-----" << endl;
    DString T, Sub;
    char chars[] = "Hello World!";
    StrAssign(T, chars);
    SubString(Sub, T, 3, 5);

    cout << "-----比大小-----" << endl;
    DString a, b;
    StrAssign(a, (char*)"abstract");
    StrAssign(b, (char*)"abstraction");
    int comp = StrCompare(a, b);
    if (comp > 0) {
        cout << "a > b" << endl;
    } else if (comp = 0) {
        cout << "a = b" << endl;
    } else {
        cout << "a < b" << endl;
    }

    cout << "-----模式匹配-----" << endl;
    DString S, Pat;
    StrAssign(S, (char*)"aaabaaabbbabaa");
    StrAssign(Pat, (char*)"babb");

    int* Next = GetNext(false, Pat);
    int* Nextval = GetNext(true, Pat);


    for (int i = 1; i <= Pat.length; i++) {
        cout << Next[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= Pat.length; i++) {
        cout << Nextval[i] << " ";
    }
    cout << endl;

    cout << "(KMP_Index)子串位置: " << Index_KMP(S, Pat, Next) << endl;
    cout << "(KMP_Optimized_Index)子串位置: " << Index_KMP(S, Pat, Nextval) << endl;

    return 0;
}
