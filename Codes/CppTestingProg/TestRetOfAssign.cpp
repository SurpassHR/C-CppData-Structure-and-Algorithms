//
// Created by h30045134 on 2024/9/23.
//
#include <iostream>

int main()
{
    int alpha, beta = 10;
    float gamma = 5.2e1;
    int a = (alpha = static_cast<int>(gamma));
    std::cout << a;
    std::cout << (alpha = static_cast<int>(gamma));
    std::cout << alpha;
    std::cout << static_cast<float>(beta);
    return 0;
}