#include <iostream>
#include <atomic>
#include <cstdint>

int main()
{
    int i = 3;
    int j = 4;
    int k = 5;
    k > 0 ? i++ : ++j;
    std::cout << i << "," << j << std::endl;
}