#include "SString.h"
#include <iostream>
using namespace std;

int main() {
    SString T, Sub, S, Pat;
    char chars[] = "Hello World!";
    char chars_[] = "Hello My World!";
    StrAssign(T, chars);
    StrPrint(T);
    SubString(Sub, T, 4, 3);
    StrPrint(Sub);
    StrAssign(S, chars_);
    cout << (StrCompare(T, S) < -1 ? "T小于S" : "T大于S") << endl;

    cout << "-----S = \"Hello World!\", Pat = \"llo\"-----" << endl;

    StrAssign(Pat, (char *)"llo");
    cout << "子串位置: " << Index(T, Pat) << endl;
    cout << "子串位置: " << Index(0, T, Pat) << endl;
    cout << "子串位置: " << Index_Improved(S, Pat) << endl;

    // 测试 KMP

    cout << "-----S = \"aaabaaaaab\", Pat = \"aaaab\"" << endl;

    SString S__;
    SString Pat__;
    StrAssign(S__, (char *)"aaabaaaaab");
    StrAssign(Pat__, (char *)"aaaab");
    int *Next__ = GetNext(Pat__);
    int *Nextval__ = GetNextval(Pat__);
    cout << "(Index_Next)子串位置: " << Index_KMP(S__, Pat__, Next__) << endl;
    cout << "(Index_Nextval)子串位置: " << Index_KMP(S__, Pat__, Nextval__) << endl;

    // 测试朴素方法
    cout << "(Index)子串位置: " << Index(S__, Pat__) << endl;

    return -1;
}
