#include <bits/stdc++.h>

int main() {
    int number = 50;
    std::bitset<32> bin(number);
    std::string binStr = bin.to_string();
    const char *binCStr = binStr.c_str();
    std::cout << bin << std::endl;
    printf("%s\n", binCStr);
    return 0;
}