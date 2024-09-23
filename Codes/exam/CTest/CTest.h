#include <iostream>
#include "CExample.h"
class CTest {
public:
    CTest() {
        std::cout << "CTest::CTest() called!" << std::endl;
    }
    virtual ~CTest() = default;
private:
    static CExample m_CExampleobj;
    static CExample m_CExampleobj1;
};