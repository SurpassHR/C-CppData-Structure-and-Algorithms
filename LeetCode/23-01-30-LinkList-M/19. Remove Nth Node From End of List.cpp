#include "../LeetCode.h"

/* Definition for singly - linked list. */
struct ListNode {
    int val;
    ListNode* next;

    ListNode(): val(0), next(nullptr) { }
    ListNode(int x): val(x), next(nullptr) { }
    ListNode(int x, ListNode* next): val(x), next(next) { }
};

class Solution {
public:
    ListNode* createLinkList(vector<int> arr) {
        ListNode* head = new ListNode(arr[0]);
        ListNode* t = head;
        vector<int>::iterator it = arr.begin();
        it++;
        for (; it != arr.end(); it++) {
            ListNode* p = new ListNode(*it);
            t->next = p;
            t = p;
        }

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1, * p2, * q;
        p1 = head;
        p2 = p1;
        while (n > 0 && p2) {
            p2 = p2->next;
            n--;
        }
        if (!p2) {
            if (n == 0) {
                if (p1 == head) {
                    return p1->next;
                }
                q = p1->next;
                p1->next = q->next;
                delete(q);
                return head;
            }
            return nullptr;
        }
        while (p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        q = p1->next;
        p1->next = q->next;
        delete(q);

        return head;
    }
};

int main() {
    Solution sl;
    ListNode* ans, * head;
    vector<int> arr = { 1,2 };
    int n = 2;
    head = sl.createLinkList(arr);
    ans = sl.removeNthFromEnd(head, n);
    ListNode* t = ans;
    while (t != nullptr) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}
