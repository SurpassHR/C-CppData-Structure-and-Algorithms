// 2. Add Two Numbers - recurse

#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *begin, *tail;
        tail = begin;
        ListNode *l1Begin = l1;
        ListNode *l2Begin = l2;
        int carry = 0;
        while ((l1Begin != nullptr) && (l2Begin != nullptr)) {
            ListNode *tmp = new ListNode;
            int val = l1Begin->val + l2Begin->val;
            carry = val / 10;
            tmp->val = val % 10;
            tail->next = tmp;
            tail = tail->next;
            l1Begin = l1Begin->next;
            l2Begin = l2Begin->next;
        }
        if (l1Begin != nullptr) {
            while (l1Begin != nullptr) {
                tail->next = l1Begin;
                l1Begin = l1Begin->next;
                tail = tail->next;
            }
        } else if (l2Begin != nullptr) {
            while (l2Begin != nullptr) {
                tail->next = l2Begin;
                l2Begin = l2Begin->next;
                tail = tail->next;
            }
        } else {}
        return begin;
    }
};

void printLinkList(ListNode *begin)
{
    ListNode *tmp = begin;
    while (tmp != nullptr) {
        std::cout << tmp->val << "\t";
        tmp = tmp->next;
    }
    std::cout << "\n";
}

ListNode *createLinkList(std::vector<int> &valList)
{
    ListNode *begin = new ListNode(valList[0]);
    ListNode *end = begin;
    for (auto iter = valList.begin() + 1; iter < valList.end(); ++iter) {
        ListNode *tmp = new ListNode(*iter);
        end->next = tmp;
        end = end->next;
    }
    return begin;
}

int main()
{
    Solution sl;

    std::vector<int> v1 = { 2, 4, 3 };
    std::vector<int> v2 = { 5, 6, 4 };

    ListNode *l1 = createLinkList(v1);
    ListNode *l2 = createLinkList(v2);

    printLinkList(l1);
    printLinkList(l2);

    ListNode *res = sl.addTwoNumbers(l1, l2);
    printLinkList(res);
    return 0;
}