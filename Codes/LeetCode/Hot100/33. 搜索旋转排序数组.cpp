#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        auto it = m.find(target);
        if (it != m.end()) {
            return it->second;
        }
        return -1;
    }
};

// 二分法
class Solution_ {
public:
    int rec_search(vector<int> nums, int target, int start = 0) {
        if (nums.size() == 1) {
            return start;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        // 从中间分割数组
        // 有序部分在本层完成二分查找，无序部分传递到下一层进行继续分割
        if (nums[mid] == target) {
            return start + mid;
        } else if (nums[mid] < nums[right]) {
            // 左侧不一定无序，但右侧一定有序
            rec_search(nums.);
        } else if (nums[mid] > nums[left]) {
            // 左侧一定有序，右侧不一定无序
        } else {
            return start + mid;
        }
        // 进行本层二分查找
        while (left < mid && right > mid && nums[mid] != target) {
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
            mid = (left + right) / 2;
        }
        if (nums[mid] != target) {
            return -1;
        }
        return start + mid;
    }

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        // 中值小于最右侧数则右侧数组有序，左侧无序或有序
        if (nums[mid] < nums[right]) {
            // 大于最右值则位于左侧数组
            if (target > nums[right]) {
                search(nums.assign(nums.begin(), nums.begin() + mid - 1), target);
            }
        } else {

        }
    }
};

int main() {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    int target = 0;
    cout << Solution().search(nums, target) << endl;
    return 0;
}
