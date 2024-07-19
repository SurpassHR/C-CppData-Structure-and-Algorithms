#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstddef>
#include <iterator>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *begin)
{
    ListNode *tmp = begin;
    while (tmp != nullptr) {
        printf("%d\t", tmp->val);
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode *reverseGroup(ListNode *begin, ListNode *end)
    {
        // printf("begin: %d, end: %d\n", begin->val, end->val);
        if (begin == end) {
            begin->next = nullptr;
            return end;
        }

        if (begin->next == end) {
            end->next = begin;
            begin->next = nullptr;
            return end;
        }

        if (begin->next->next == end) {
            end->next = begin->next;
            end->next->next = begin;
            begin->next = nullptr;
            return end;
        }

        // 保证链表长度大于等于3
        ListNode *p1, *p2, *p3;
        p1 = begin;
        p2 = p1->next;
        p3 = p2->next;

        while (p3->next != nullptr) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        begin->next = nullptr;
        p3->next = p2;
        p2->next = p1;
        return end;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head->next == nullptr) {
            return head;
        }

        // 获取链表的尾节点
        ListNode *tail = head->next;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        ListNode *begin = head;
        ListNode *end = begin;
        std::vector<ListNode *> revListNode;
        while (end != nullptr) {
            int cnt = 1;
            for (; (cnt < k) && (end->next != nullptr); ++cnt) {
                end = end->next;
            }
            if (cnt < k) {
                // printList(begin);
                revListNode.push_back(begin);
                break;
            }
            ListNode *endNext = end->next;
            end->next = nullptr;
            ListNode *newTail = reverseGroup(begin, end);
            revListNode.push_back(newTail);
            if (endNext == nullptr) {
                break;
            }
            begin = endNext;
            end = begin;
        }
        // 拼接
        ListNode *revHead = revListNode[0];
        ListNode *revTail = revHead;
        for (int i = 1; i < revListNode.size(); ++i) {
            while (revTail->next != nullptr) {
                revTail = revTail->next;
            }
            revTail->next = revListNode[i];
        }
        return revHead;
    }
};

int main()
{
    ListNode *begin = nullptr;

    ListNode *p1 = new ListNode;
    p1->val = 1;

    ListNode *p2 = new ListNode;
    p2->val = 2;

    ListNode *p3 = new ListNode;
    p3->val = 3;

    ListNode *p4 = new ListNode;
    p4->val = 4;

    ListNode *p5 = new ListNode;
    p5->val = 5;

    begin = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = nullptr;

    printList(begin);

    Solution s;
    ListNode *head = nullptr;
    // head = s.reverseGroup(p1, p5);
    // printList(head);

    head = s.reverseKGroup(p1, 3);
    printList(head);

    ListNode *p6 = new ListNode;
    p6->val = 6;

    head = s.reverseKGroup(p6, 1);
    printList(p6);

    return 0;
}