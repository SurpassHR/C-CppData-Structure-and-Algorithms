#include "../LeetCode.h"
using namespace std;


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
    ListNode* createList(vector<int> arr) {
        ListNode* head = new ListNode(arr[0]);
        ListNode* t = head;
        for (int i = 1; i < arr.size(); i++) {
            ListNode* p = new ListNode(arr[i]);
            t->next = p;
            t = p;
        }
        return head;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* p, * q, * r;
        p = head; q = head->next; r = q->next;
        head = q;
        while (r) {
            q->next = p;
            p->next = r;
            r = r->next;
            p = p->next;
            q = q->next;

        }
        cout << p->val << " " << q->val << endl;
        return head;
    }
};

int main() {
    vector<int> arr = { 1,2,3,4 };
    ListNode* head = Solution().createList(arr);
    ListNode* t1 = head;
    while (t1) {
        cout << t1->val << " ";
        t1 = t1->next;
    }
    cout << endl;
    ListNode* ans = Solution().swapPairs(head);
    ListNode* t2 = ans;
    while (t2) {
        cout << t2->val << " ";
        t2 = t2->next;
    }
    cout << endl;
    return 0;
}
