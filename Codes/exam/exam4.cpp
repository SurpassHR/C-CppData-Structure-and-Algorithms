#include <iostream>
using namespace std;

class CExample {
public:
    CExample();
    virtual ~CExample();
private:
    static int m_iValuel;
    int m_iValue2;
};

/* 16 */
int main() {
    cout << sizeof(CExample) << endl;
    return 0;
}
