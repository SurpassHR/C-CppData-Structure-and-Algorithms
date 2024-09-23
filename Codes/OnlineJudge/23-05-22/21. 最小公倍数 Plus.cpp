#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n) {
        int i = 1;
        vector<int> nums = {};
        // 判断输入过的数字中有没有因数
        for (int j = 1; j <= n; j++) {
            int newNum = j;
            for (auto it = nums.begin(); it != nums.end(); it++) {
                if (newNum % *it == 0) {
                    newNum /= *it;
                }
            }
            nums.push_back(newNum);
        }
        // sort(nums.begin(), nums.end());
        // auto last = unique(nums.begin(), nums.end());
        // nums.erase(last, nums.end());
        int Lcm = 1;
        for (auto it : nums) {
            Lcm *= it;
        }
        cout << Lcm << endl;
    }
    return 0;
}