# BackTracking算法

是递归算法的衍生产物。

## 1.对于某些n重for循环问题

### LeetCode 17. 9宫格键盘的字母组合

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/11/09/200px-telephone-keypad2svg.png)



**示例 1：**

```txt
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**示例 2：**

```txt
输入：digits = ""
输出：[]
```

**示例 3：**

```txt
输入：digits = "2"
输出：["a","b","c"]
```


**提示：**

-   `0 <= digits.length <= 4`
-   `digits[i]` 是范围 `['2', '9']` 的一个数字。

**题解：**

显然键盘数字与字母之间的映射可以通过map或字符串数组来实现：

```C++
vector<string> mapLetter;
mapLetter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
map<int, string> mapLetter;
mapLetter.emplace(2, "abc");
/* ... */
```

当输入"23"时（`digits = "23"`），可能对应的字母有以下可能：`"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"`，对于可知层数的循环（当前为2），可以直接通过for循环解决问题：[二重for循环.cpp](./%E4%BA%8C%E9%87%8Dfor%E5%BE%AA%E7%8E%AF.cpp)

```C++
vector<string> possibleCombination;
/* 二重for循环 */
// 当前数字映射字符串
int digit2 = digits[0];
int digit3 = digits[1];
string letter2 = mapLetter[digit2];
string letter3 = mapLetter[digit3];
string s = "";
for (int i = 0; i < letter2.size(); i++) {
    s = "";
    s += letter2[i];
    for (int j = 0; j < letter3.size(); j++) {
        s.push_back(letter3[j]);
        possibleCombination.push_back(s);
        s.pop_back();
    }
}
```

```bash
#Input
23
# Output
ad ae af bd be bf cd ce cf
```

2位数字时需要2重for循环，则n位数字时需要n重for循环，我们无法控制for循环的层数，但是可以把每一层for循环抽象成一次操作，并写下完成n重for循环的条件，构成递归。

对于单个数字的一次for循环：

```C++
for (int i = 0; i < mapLetter[digit].size(); i++) {
    // ...
}
```

因为要遍历完一次映射字符串，所以索引`i`的范围为`[0, letter.size())`，同时需要知晓当前进行到第几次for循环，显然，当进行到第n次for循环时退出循环，即当记录for循环深度的变量index等于`digits.size()`时递归停止，上一步已经累加的字符串s也要传到下一层。此时可以写出递归函数：[递归for循环.cpp](./%E9%80%92%E5%BD%92for%E5%BE%AA%E7%8E%AF.cpp)

```C++
// 第 index 层循环
void func(string s, int index) {
    // 递归终止
    if (index >= digits.size()) {
        // vector<string> ans; 全部组合
        ans.push_back(s);
        return ;
    }
    // 当前的数字
    int digit = digits[index] - '0';
    // 当前数字映射的字符串
    string letter = mapLetter[digit];
    // 第 index 个数字的每一个映射的字符都与上一层输出的字符串进行组合
    for (int i = 0; i < letter.size(); i++) {
        // 第 index 层循环的第 i 次组成的字符串
        s.push_back(letter[i]);
        // 进行第 index + 1 层循环
        func(s, index + 1);
        // 若要进行第 index 层循环的第 i + 1 次，要将字符串还原到上一步
        s.pop_back();
    }
}
```

```bash
# Input
23
# Output
ad ae af bd be bf cd ce cf
```
## 2.针对回溯超时问题的优化解决方案

### 2.1 剪枝 LeetCode 18. 四数之和

给你一个由 `n` 个整数组成的数组 `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且**不重复**的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：

-   `0 <= a, b, c, d < n`
-   `a`、`b`、`c` 和 `d` **互不相同**
-   `nums[a] + nums[b] + nums[c] + nums[d] == target`

你可以按 **任意顺序** 返回答案 。



**示例 1：**

```txt
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**示例 2：**

```txt
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
```


**提示：**

-   `1 <= nums.length <= 200`
-   `-10^9 <= nums[i] <= 10^9`
-   `-10^9 <= target <= 10^9`

在解答这道题时出现了超时的情况，原因是对于重复的数字也进行了递归计算，首先可以写出正常的递归算法：[](./递归四数之和.cpp)

```C++
class Solution {
private:
    int tar;
    vector<int> myNums, sumNums;
    vector<vector<int>> ans;

    void recursion(int startIndex, int sum) {
        if (sumNums.size() == 4 && sum == tar) {
            ans.push_back(sumNums);
            return;
        }
        for (int i = startIndex; i < myNums.size(); i++) {
            sumNums.push_back(myNums[i]);
            recursion(i + 1, sum + myNums[i]);
            sumNums.pop_back();
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        tar = target;
        myNums = nums;
        recursion(0, 0);

        return ans;
    }
};
```

可以进行的剪枝操作：

设$n$为已求和元素个数。

 - 剩余元素个数与当前元素个数之和不足$4$，此时直接终止递归。
 - 当前元素之和加上$(n-1)$倍后续最小元素仍然大于$target$，此时直接终止递归。
 - 当前元素之和加上$(n-1)$倍后续最大元素仍然小于$target$，此时跳过该次循环。

可以进行的去重操作：

 - 当前元素不是该层循环的首元素时，若当前元素与上衣元素相同则跳过该次循环。

注意特殊测试样例：

 - 大于`INT32_MAX`的元素。

 > **注意：**`vector<int>().size()`的返回值为`unsigned`类型，为避免不必要的麻烦先将其赋值给`int`型变量。

**修改后题解：**

```C++
class Solution {
private:
    int tar, myNumsSize;
    vector<int> myNums, sumNums;
    vector<vector<int>> ans;

    void recursion(int startIndex, long sum) {
        int sumSize = sumNums.size();
        if (sumSize == 4 && sum == tar) {
            ans.push_back(sumNums);
            return;
        }
        for (int i = startIndex; i < myNumsSize; i++) {
            // 去重
            if (i > startIndex && myNums[i] == myNums[i - 1]) {
                continue;
            }
            // 剪枝
            if (4 - sumSize > myNumsSize - i) {
                return;
            }
            if ((long)myNums[i] + (long)sum + (long)(3 - sumSize) * myNums[i + 1] > tar) {
                return;
            }
            if ((long)myNums[i] + (long)sum + (long)(3 - sumSize) * myNums[myNumsSize - 1] < tar) {
                continue;
            }
            sumNums.push_back(myNums[i]);
            recursion(i + 1, sum + myNums[i]);
            sumNums.pop_back();
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        myNums = nums;
        myNumsSize = myNums.size();
        tar = target;
        recursion(0, 0);

        return ans;
    }
};
```
