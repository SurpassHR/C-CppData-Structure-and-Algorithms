#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char acX[] = "abcdefg";
    char acY[] = { 'a','b','c','d','e','f','g' };
    cout << (strcmp(acX, acY) == 0 ? 1 : 0) << endl;
    cout << (sizeof(acX) == sizeof(acY) ? 1 : 0) << endl;
    cout << "sizeof(acX): " << sizeof(acX) << ", sizeof(acY): " << sizeof(acY) << endl;

    return 0;
}