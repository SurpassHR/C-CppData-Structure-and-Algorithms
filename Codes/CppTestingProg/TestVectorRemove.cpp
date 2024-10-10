//
// Created by h30045134 on 2024/9/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Func1(std::vector<int> numbers)
{
    std::remove_if(numbers.begin(), numbers.end(), [](int x)->bool {
        return x < 0;
    });
    return numbers;
}

std::vector<int> Func2(std::vector<int> numbers)
{
    auto pos = std::remove_if(numbers.begin(), numbers.end(), [](int x)->bool {
        return x < 0;
    });
    return std::vector<int>(numbers.begin(), pos);
}

std::vector<int> Func3(std::vector<int> numbers)
{
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int x)->bool {
        return x < 0;
    }), numbers.end());
    return numbers;
}

std::vector<int> Func4(std::vector<int> numbers)
{
    std::vector<int> newNumbers;
    std::remove_copy_if(numbers.begin(), numbers.end(), newNumbers.begin(),
                        [](int x)->bool {
                            return x < 0;
                        });
    return newNumbers;
}

void PrintVector(std::vector<int> &v)
{
    std::for_each(v.begin(), v.end(), [](auto i){std::cout << i << "\t";});
    std::cout << "\n";
}

int main()
{
    std::vector<int> a{-2, -1, 0, 1, 2, 3};
    std::vector<int> b(a), c(a), d(a);
    a = Func1(a);
    PrintVector(a);
    b = Func2(b);
    PrintVector(b);
    c = Func3(c);
    PrintVector(c);
    d = Func4(d);
    PrintVector(d);
    return 0;
}