#include "LeetCodeLList.h"

ListNode* createLinkList(std::vector<int> arr) {
    ListNode* ret = new ListNode(arr[0]), * t = ret;
    for (int i = 1; i < arr.size(); i++) {
        ListNode* p = new ListNode(arr[i]);
        t->next = p;
        t = t->next;
    }
    return ret;
}

std::vector<ListNode*> createLinkList(std::vector<std::vector<int>> arr) {
    std::vector<ListNode*> ret;
    for (std::vector<int> it : arr) {
        if (!it.size()) {
            ret.push_back(nullptr);
            continue;
        }
        ListNode* head = new ListNode(it[0]), * t = head;
        for (int i = 1; i < it.size(); i++) {
            ListNode* p = new ListNode(it[i]);
            t->next = p;
            t = t->next;
        }
        ret.push_back(head);
    }
    return ret;
}
