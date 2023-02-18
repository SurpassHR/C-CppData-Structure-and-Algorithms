# C++Lambda 和 模板

在 LeetCode 的 23 题中见识到了一个简洁的合并n个链表的写法，其中用到了 `priority_queue` 模板和 `lambda` 函数，在我没接触过太多 C++ STL 的情况下见识到了代码简洁的美。

**题目：**

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*



**Example 1:**

```txt
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

**Example 2:**

```txt
Input: lists = []
Output: []
```

**Example 3:**

```txt
Input: lists = [[]]
Output: []
```


**Constraints:**

-   `k == lists.length`
-   `0 <= k <= 10^4`
-   `0 <= lists[i].length <= 500`
-   `-10^4 <= lists[i][j] <= 10^4`
-   `lists[i]` is sorted in **ascending order**.
-   The sum of `lists[i].length` will not exceed `10^4`.

**我的写法：**

把 $k$ 个list合并的问题分割成了 $k - 1$ 个 $2$ lists合并问题。

```C++
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret, * p1, * p2, * t;
        p1 = l1; p2 = l2;
        // 为头结点赋值
        if (p1->val < p2->val) {
            ret = p1;
            p1 = p1->next;
        } else {
            ret = p2;
            p2 = p2->next;
        }
        ret->next = nullptr;
        t = ret;
        // 当 l1 l2 均非空时
        while (p1 || p2) {
            // 当 l1 非空 l2 为空时
            if (p1 && !p2) {
                t->next = p1;
                break;
                // 当 l2 非空 l1 为空时
            } else if (p2 && !p1) {
                t->next = p2;
                break;
                // 当 l1 l2 均非空时
            } else {
                // 若 l1元素 小于 l2元素 l1元素
                if (p1->val < p2->val) {
                    t->next = p1;
                    p1 = p1->next == nullptr ? nullptr : p1->next;
                    // 若 l1元素 小于 l2元素 l1元素
                } else {
                    t->next = p2;
                    p2 = p2->next == nullptr ? nullptr : p2->next;
                }
                t = t->next;
                t->next = nullptr;
            }
        }

        return ret;
    }
public:
    ListNode* mergeKLists(vector<ListNode*> lists) {
        ListNode* ret, * t;
        // 若当前数组为空
        if (lists.size() == 0) {
            return nullptr;
        }
        // 若当前数组仅有1链表
        if (lists.size() == 0) {
            return nullptr;
        }
        // 去除数组中为空的链表
        vector<ListNode*>::iterator it = lists.begin();
        for (; it != lists.end(); it++) {
            if (*it == nullptr) {
                lists.erase(it);
                it--;
            }
        }
        ret = lists[0];
        t = ret;
        for (int i = 1; i < lists.size(); i++) {
            ret = mergeTwoLists(ret, lists[i]);
        }

        return ret;
    }
};
```

```bash
# Input
{{1,4,5},{1,3,4},{2,6}}
# Output
1 1 2 3 4 4 5 6
```

## 迭代器问题

其中我发现的第一个问题就是迭代器`iterator`与数组下标的区别，当通过迭代器删除当前元素时如`vector<ListNode*>::erase(_pos)`时，元素被删除了，但迭代器既没有消失，也没有停留在原处，而是由于下一个元素占位，指向了下一个元素。

**我一开始错误的写法：**

```C++
vector<ListNode*>::iterator it = lists.begin();
for (; it != lists.end(); it++) {
    if (*it == nullptr) {
        lists.erase(it);
    }
}
```

**正确的写法：**

```C++
/* 写法一 */
typedef vector<ListNode*>::iterator itor;
for (itor it = lists.begin(); it != lists.end(); it++) {
    if (*it == nullptr) {
        lists.erase(it);
        it--;
    }
}
/* 写法二 */
itor it = lists.begin();
while (it != lists.end()) {
    if (*it == nullptr) {
        lists.erase(it);
    } else {
        it++;
    }
}
```

## 更简洁的二链表合并

```C++
/* 递归 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```

## 通过Lambda函数比较大小

```C++
bool lambda(ListNode* l1, ListNode* l2) = []{return }
```
