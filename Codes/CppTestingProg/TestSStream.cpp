//
// Created by h30045134 on 2024/9/26.
//

#include <sstream>
#include <iostream>

void Test1()
{
    std::ostringstream output;
    output << "Hello world!";
    const char *str = output.str().c_str();
    std::cout << str << std::endl;
}

void Test2()
{
    std::ostringstream output;
    output << "Hello world!";
    auto outputStr = output.str();
    const char *str = outputStr.c_str();
    std::cout << str << std::endl;
}

void Test3()
{
    std::ostringstream output("Hello world!");
    std::cout << output.str() << std::endl;
}

void Test4()
{
    std::ostringstream output;
    output << "Hello world!";
    std::string outputStr = output.str();
    std::cout << outputStr.c_str() << std::endl;
}

void Intro()
{
    // std::stringstream 用于格式化字符串
    std::stringstream ss;
    ss << "Dec: " << 89 << " Hex: " << std::hex << 89 << " Oct: " << std::oct << 89;
    std::cout << ss.str() << std::endl;

    int a, b, c;
    std::string s0, s1, s2;

    ss >> s0 >> std::dec >> a >> s1 >> std::dec >> b >> s2 >> std::dec >> c;
    s0 += " ";
    s1 = " " + s1 + " ";
    s2 = " " + s2 + " ";

    std::cout << s0 << a << s1 << b << s2 << c;
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Intro();
    return 0;
}