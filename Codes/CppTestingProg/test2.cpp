#include <bits/stdc++.h>

class Person {
public:
    Person() = default;
    ~Person() = default;
private:
    static void PrintAge() { std::cout << m_age << std::endl; }
private:
    unsigned m_age{ 0 };
};

int main() {
    return 0;
}