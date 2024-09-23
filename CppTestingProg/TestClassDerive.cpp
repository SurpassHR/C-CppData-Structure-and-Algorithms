#include <bits/stdc++.h>

class Base {
public:
    Base()
    {
        std::cout << "Base" << "\n";
    }
    virtual ~Base()
    {
        std::cout << "~Base" << "\n";
    }
    virtual void Print()
    {
        std::cout << "Base" << "\n";
    }
};

class Derive : public Base {
public:
    Derive()
    {
        std::cout << "Derive" << "\n";
    }
    ~Derive() override
    {
        std::cout << "~Derive" << "\n";
    }
    void Print()
    {
        std::cout << "Dervie" << "\n";
    }
};

// int main()
// {
//     Base *base = new Derive;
//     base->Print();
//     base->Base::Print();
//     delete base;
//     return 0;
// }

int main()
{
    int i = 0;
    int j = 0;
    for (i = 10; i >= 0; --i) {
        for (j = 10; j == 1; --j) {
            i = j;
        }
    }
    std::cout << i << "," << j << std::endl;
}
