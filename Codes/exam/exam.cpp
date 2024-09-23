#include <iostream>
#include <vector>
using namespace std;

class CA {
public:
    CA() = default;
private:
    int m_iTime;
public:
    int GetTime();
    int SetTime(int time);
};

class CParent {
public:
    CParent() { }
    virtual ~CParent() { }
public:
    virtual void Print() {
        std::cout << 1;
    }
};

class CSon: public CParent {
public:
    CSon() { };
    virtual ~CSon() { };
public:
    void Print() {
        std::cout << 2;
    }
};

void Test1(CParent& oParent) {
    oParent.Print();
}

void Test2(CParent oParent) {
    oParent.Print();
}

int main() {
    // vector<int> vec = { 1, 2, 3 };
    // for (auto x : vec) {
    //     x++;
    // }
    // for (auto x : vec) {
    //     cout << x << endl;
    // }

    // cout << sizeof(CA) << endl;

    CSon* p = new CSon();
    Test1(*p);
    Test2(*p);
    delete p;


    return 0;
}