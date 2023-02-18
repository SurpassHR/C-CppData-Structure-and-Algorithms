#include <iostream>
#include <ctime> // time()函数
#include <cstdlib> // srand() set random seed; rand()

using namespace std;

int main() {
    srand(time(NULL));
    cout << "输出一个[0, 100)的整数: " << endl;
    cout << rand() % 100 << endl;
    // cout << RAND_MAX << endl;  // RAND_MAX = 214738364
    cout << "输出一个[30, 90)的整数" << endl;
    cout << 30 + rand() % 60 << endl;

    return 0;
}
