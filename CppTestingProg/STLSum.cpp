#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <chrono>
using namespace std;

int main() {
    vector<int> nums = { 2, 1, 5, 8, 3 };
    auto time1 = chrono::high_resolution_clock::now();
    int sum1 = accumulate(nums.begin(), nums.end(), 0);
    auto time2 = chrono::high_resolution_clock::now();
    int sum2 = reduce(nums.begin(), nums.end(), 0);
    auto time3 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms1 = time2 - time1;
    chrono::duration<double, milli> ms2 = time3 - time2;
    cout << "accumulate cost: " << ms1.count() << " ms" << ", " << "reduce cost: " << ms2.count() << " ms" << endl;
    return 0;
}
