#include <iostream>
#include <map>

int main() {
    int n, num;
    std::map<int, int> count;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        count[num] += 1;
    }

    for (std::map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    return 0;
}
