/* 二分查找的一维数组简单实现 */
#include "../LeetCode.h"

class Solution {
public:
    int binarySearch(vector<int> v, int target) {
        int left, right;
        left = 0;
        right = v.size() - 1;
        int mid;
        mid = (left + right) / 2;

        while (left < mid && right > mid && v[mid] != target) {
            cout << "mid = " << mid << " " << "left = " << left << " " << "right = " << right << endl;
            if (target > v[mid]) {
                left = mid;
            } else {
                right = mid;
            }
            mid = (left + right) / 2;
        }

        if (v[mid] != target) return -1;

        return mid;
    }
};

int main(void) {
    Solution sl;
    vector<int> v = { 9, 13, 26, 27, 45, 59, 77, 83, 99 };
    int target;
    cin >> target;
    int mid = sl.binarySearch(v, target);
    cout << mid << endl;

    return 0;
}
