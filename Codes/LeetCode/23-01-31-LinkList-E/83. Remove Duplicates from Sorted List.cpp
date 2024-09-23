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
    ListNode* createLinkList(vector<int> arr) {
        ListNode* head = new ListNode(arr[0]);
        ListNode* t = head;
        int arrLen = arr.size();
        for (int i = 1; i < arrLen; i++) {
            ListNode* p = new ListNode(arr[i]);
            t->next = p;
            t = p;
        }

        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pi = head;
        while (pi && pi->next) {
            if (pi->val == pi->next->val) {
                ListNode* del = pi->next;
                pi->next = pi->next->next;
                delete del;
            } else {
                pi = pi->next;
            }
        }
        return head;
    }
};

int main() {
    vector<int> arr = { 1,1,2 };
    Solution sl;
    ListNode* head;
    head = sl.createLinkList(arr);
    head = sl.deleteDuplicates(head);
    ListNode* t = head;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}
