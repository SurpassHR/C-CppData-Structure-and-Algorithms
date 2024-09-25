//
// Created by h30045134 on 2024/9/24.
//

#include <iostream>
#include <vector>

int main()
{
    int a = 1, b = 5;
    int &r = a;
    auto t = std::tie(r, b); // 传入左值引用，修改std::tuple的值就是修改原变量值
    std::get<0>(t) = 3;
    std::get<1>(t) += 2;
    std::cout << a << " " << b << std::endl;

    auto tt = std::make_pair(a, b); // 传入右值引用，修改std::pair的值就只是修改成员的值
    std::get<0>(tt) = 4;
    std::get<1>(tt) += 2;
    std::cout << a << " " << b << std::endl;

    std::vector<int>v({a, b});

    return 0;
}