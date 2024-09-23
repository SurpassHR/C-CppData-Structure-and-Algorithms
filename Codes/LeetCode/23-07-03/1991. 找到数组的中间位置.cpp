#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution_ {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int sumLeft = reduce(nums.begin(), nums.begin() + i, 0);
            int sumRight = reduce(nums.end() - (size - i - 1), nums.end(), 0);
            if (sumLeft == sumRight) {
                return i;
            }
        }
        return -1;
    }
};

class Solution__ {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        int sum = reduce(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < size; i++) {
            if (leftSum + nums[i] == sum) {
                return i;
            }
            leftSum += nums[i];
            sum -= nums[i];
        }
        return -1;
    }
};

int main() {
    vector<int> nums = { 1, 7, 3, 6, 5, 6 };
    // int size = nums.size();
    // int i = 3;
    // int sumLeft = reduce(nums.begin(), nums.begin() + i, 0);
    // int sumRight = reduce(nums.end() - (size - 1 - i), nums.end(), 0);
    // cout << sumLeft << ", " << sumRight << endl;
    int ret = Solution__().pivotIndex(nums);
    cout << ret << endl;
    return 0;
}
