# 两数之和

#### **1. 两数之和**

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`*  的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

  

**示例 1：**

```txt
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```txt
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```txt
输入：nums = [3,3], target = 6
输出：[0,1]
```


**提示：**

-   `2 <= nums.length <= 10^4`
-   `-10^9 <= nums[i] <= 10^9`
-   `-10^9 <= target <= 10^9`
-   **只会存在一个有效答案**

  

**进阶：**你可以想出一个时间复杂度小于 `O(n^2)` 的算法吗？

**题解：**使用哈希存储的`multimap`来存储`nums`的下标和数据，然后在遍历整个数组的过程中逐渐填充`multimap`并且使用`equal_range()`来找出`multimap`中符合`target - nums[i]`大小的值的范围

```C++
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 剪枝
        if (nums.size() == 2) return {0, 1};
        // 定义一个multimap
        multimap<int, int> mmapNums;
        vector<int> ans;
        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            // 当前的数字为
            int cur = nums[i];
            // 希望找到的与nums[i]和为target的第二个数为
            int toFind = target - cur;
            // 用equal_range()返回一个范围，但题目指出只有一组解，所以若存在则返回的pair应该second = first + 1
            auto itFind = mmapNums.equal_range(toFind);
            // 指向第二个数的迭代器
            auto left = itFind.first;
            // 同时第一个大于target - nums[i]的数的迭代器为
            auto right = itFind.second;
            while (upper != lower) {
                if (upper->second != i) {
                    ans.push_back(i);
                    ans.push_back(upper->second);
                    // 确认找到后直接返回结果
                    return ans;
                }
                upper++;
            }
            // 每次没有满足要求的数字都加入mmap
            mmapNums.emplace(nums[i], i);
        }
        return ans;
    }
}
```

**分析：**算法的最好时间复杂度为当`nums.size() == 2`时，直接返回，时间复杂度为`O(1)`，最坏时间复杂度为在`multimap`中的倒数第一和倒数第二个元素之和等于`target`，此时若哈希查找算法也是最坏时间复杂度，则总的时间复杂度为`O(n^2)`，但正常情况下`equal_range()`查找的时间复杂度一定小于`O(n)`
