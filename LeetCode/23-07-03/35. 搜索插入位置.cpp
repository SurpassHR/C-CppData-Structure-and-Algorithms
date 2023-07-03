#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = (left + right) / 2;
        while (left < mid && right > mid && nums[mid] != target) {
            if (target < nums[mid]) {
                right == mid;
            } else {
                left == mid;
            }
            mid = (left + right) / 2;
        }
        return mid;
    }
};
