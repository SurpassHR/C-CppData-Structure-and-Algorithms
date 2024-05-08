#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ret;
        multimap<int, int> mmap;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            // 要查找的第二个数字
            int toFind = target - nums[i];
            // 在 multimap 中查找
            auto itToFind = mmap.equal_range(toFind);
        }
    }
};

int main() {
    return 0;
}