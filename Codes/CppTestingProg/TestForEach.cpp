//
// Created by h30045134 on 2024/9/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };
    std::for_each(numbers.begin(), numbers.end(), [](auto &i){i += 2;});
    std::for_each(numbers.begin(), numbers.end(), [](auto i){std::cout << i << "\t";});
    return 0;
}