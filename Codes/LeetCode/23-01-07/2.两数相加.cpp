/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

 // @lc code=start
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */


  // 高精度加法
#include "../LeetCode.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) { }
    ListNode(int x): val(x), next(nullptr) { }
    ListNode(int x, ListNode* next): val(x), next(next) { }
};

class Solution {
public:
    ListNode* createList(int arr[], int len) {
        int i;
        ListNode* head = new ListNode(arr[0]);
        ListNode* tmp = head;
        for (i = 1; i <= len; i++) {
            tmp->next = new ListNode(arr[i]);
            tmp = tmp->next;
        }

        return head->next;
    }

    void printList(ListNode* l, int len) {
        ListNode* t = l;
        while (len > 0) {
            cout << t->val << endl;
            t = t->next;
            len--;
        }

        return;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 模拟加法进位
        ListNode* head, * t;
        t = head;
        int carry = 0;

        // 尾插法创建新链表
        while (l1->next || l2->next) {
            // 创建新结点
            ListNode* p = new ListNode(0);
            // 当前位仅有l1
            if (!l2) {
                int sum = l1->val + carry;
                p->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
            }

            // 当前位仅有l2
            else if (!l1) {
                int sum = l2->val + carry;
                p->val = sum % 10;
                carry = sum / 10;
                l2 = l2->next;
            }

            // 当前位既有l1也有l2
            else {
                int sum = l1->val + l2->val + carry;
                p->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            t->next = p;
            t = p;
        }
        if (carry) {
            t->next = new ListNode(1, nullptr);
            t = t->next;
        }

        return head->next;
    }
};
// @lc code=end
