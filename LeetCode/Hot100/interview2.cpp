#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p1, * p2;
        p1 = head; p2 = p1->next;
        while (p1 && p2) {
            if (p1->val != p2->val) {
                p1 = p1->next;
                p1->val = p2->val;
            }
            p2 = p2->next;
        }
        p1->next = NULL;
        return head;
    }
};

int main() {
    vector
    Solution sl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    ListNode* ans = sl.removeDuplicateNodes(n1);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << "\n";
    return 0;
}
