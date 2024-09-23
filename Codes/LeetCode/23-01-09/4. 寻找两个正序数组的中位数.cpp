#include "../LeetCode.h"

// 要求: 时间复杂度为 O(log(m+n))
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i, j, median, pre, next;

        // 合并数组
        vector<int> merge(nums1.size() + nums2.size());
        for (i = 0, j = 0; i < nums1.size() && j < nums2.size() && i + j < merge.size();) {
            if (nums1[i] < nums2[j]) {
                merge[i + j] = nums1[i];
                i++;
            } else {
                merge[i + j] = nums2[j];
                j++;
            }
        }
        if (i == nums1.size()) {
            while (j < nums2.size()) {
                merge[i + j] = nums2[j];
                j++;
            }
        } else {
            while (i < nums1.size()) {
                merge[i + j] = nums1[i];
                i++;
            }
        }

        // 找中位数
        for (int i : merge) cout << i << " ";
        cout << endl;

        if (merge.size() % 2 == 1)
            return merge[merge.size() / 2];
        else
            return ((double)merge[merge.size() / 2] + (double)merge[merge.size() / 2 - 1]) / 2;
    }
};

int main(void) {
    double median;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    median = Solution().findMedianSortedArrays(nums1, nums2);
    cout << median << endl;

    return 0;
}
