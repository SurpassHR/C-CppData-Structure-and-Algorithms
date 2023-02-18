#include "../LeetCode.h"

class Solution {
public:
    // 二分查找：时间复杂度为O(log(m + n))
    // nums1.size() == m, nums2.size() == n
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 讨论其中一个数组为空的特殊情况
        if (nums1.size() == 0) {
            if (nums2.size() % 2 == 0) {
                return ((double)nums2[nums2.size() / 2] + (double)nums2[nums2.size() / 2 - 1]) / 2;
            } else {
                return nums2[nums2.size() / 2];
            }
        } else if (nums2.size() == 0) {
            if (nums1.size() % 2 == 0) {
                return ((double)nums1[nums1.size() / 2] + (double)nums1[nums1.size() / 2 - 1]) / 2;
            } else {
                return nums1[nums1.size() / 2];
            }
        }

        // 创建上下两根分界线，初始值分别设为中间元素
        int spLine1, spLine2;
        spLine1 = (0 + nums1.size()) / 2;
        spLine2 = (0 + nums2.size()) / 2;

        // 找到位于分界线两侧的元素，它们是分界线两侧的最大值和最小值
        int leftMax1, leftMax2, rightMin1, rightMin2;
        leftMax1 = nums1[spLine1];
        leftMax2 = nums2[spLine2];
        rightMin1 = nums1[spLine1 + 1];
        rightMin2 = nums2[spLine2 + 1];

        // 二分法上下边界
        int left1, right1, left2, right2;
        left1 = 0;
        right1 = nums1.size();
        left2 = 0;
        right2 = nums2.size();

        int total = nums1.size() + nums2.size();
        // 左侧元素个数，右侧元素个数为totalRight = total - totalLeft;
        int totalLeft = spLine1 + spLine2;

        // 循环条件：当左侧的最大值大于右侧的最小值
        // 调整：将左侧最大值部分的分界线左移，同时右侧最小值部分的分界线右移
        // 调整方法：二分法
        while (max(leftMax1, leftMax2) > min(rightMin1, rightMin2)) {
            if (leftMax1 > leftMax2) {
                spLine1 -= totalLeft / 2;
                spLine2 += totalLeft / 2;
                // 调整边界
                left1 = left1;
                right1 = spLine1;
                left2 = spLine2;
                right2 = right2;
            } else {
                spLine1 += totalLeft / 2;
                spLine2 -= totalLeft / 2;
                // 调整边界
                left1 = spLine1;
                right1 = right1;
                left2 = left2;
                right2 = spLine2;
            }

            if (left1 == right1 || left2 == right2) {
                return ((double)max(leftMax1, leftMax2) + (double)min(rightMin1, rightMin2)) / 2;
            }
        }
        return ((double)max(leftMax1, leftMax2) + (double)min(rightMin1, rightMin2)) / 2;
    }
};

int main(void) {
    vector<int> nums1 = { 1, 3 };
    vector<int> nums2 = { 2 };

    int ans = Solution().findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;

    return 0;
}
