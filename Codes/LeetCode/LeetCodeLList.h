#ifndef _LEETCODE_LLIST_
#define _LEETCODE_LLIST_

#include <vector>

/* Definition of singly-linked list */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) { }
    ListNode(int x): val(x), next(nullptr) { }
    ListNode(int x, ListNode* next): val(x), next(next) { }
};

/* Create a singly-linked list from an array */
ListNode* createLinkList(std::vector<int> arr);

/* Create a set of singly-linked list from a 2-d array */
std::vector<ListNode*> createLinkList(std::vector<std::vector<int>> arr);

#endif
