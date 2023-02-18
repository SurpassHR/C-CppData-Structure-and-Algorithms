#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> bitSum(vector<int> nums) {
        vector<int> ans;
        for (int i : nums) {
            int sum = 0;
            while (i != 0) {
                sum += i % 10;
                i /= 10;
            }
            ans.push_back(sum);
        }

        return ans;
    }
};

int main() {
    vector<int> ans;
    Solution sl;
    vector<int> nums = { 101, 100, 999, 1234, 110 };
    ans = sl.bitSum(nums);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
