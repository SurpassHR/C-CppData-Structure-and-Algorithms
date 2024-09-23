#ifndef CEXAMPLE_H
#define CEXAMPLE_H

#include <iostream>
class CExample {
public:
    CExample() {
        std::cout << "this is a test!" << std::endl;
    }
    CExample(int iValue) {
        m_iValue = iValue;
        std::cout << "CExample(int) constructor called!" << m_iValue << std::endl;
    }
    virtual ~CExample() = default;
private:
    int m_iValue;
};

#endif