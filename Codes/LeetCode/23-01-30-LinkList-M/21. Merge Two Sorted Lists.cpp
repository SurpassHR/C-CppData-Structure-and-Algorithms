#include "../LeetCode.h"
#include "../LeetCodeLList.h"

using namespace std;

class Solution {
public:
    //     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //         if (!list1 && !list2) return nullptr;
    //         if (list1 && !list2) return list1;
    //         if (list2 && !list1) return list2;
    //         ListNode* p1 = list1, * p2 = list2;
    //         ListNode* head, * t;
    //         if (p1->val < p2->val) {
    //             head = p1;
    //             p1 = p1->next;
    //         } else {
    //             head = p2;
    //             p2 = p2->next;
    //         }
    //         t = head;
    //         t->next = nullptr;
    //         while (p1 && p2) {
    //             ListNode* q;
    //             if (p1->val < p2->val) {
    //                 q = new ListNode(p1->val);
    //                 t->next = q;
    //                 t = q;
    //                 p1 = p1->next;
    //             } else {
    //                 q = new ListNode(p2->val);
    //                 t->next = q;
    //                 t = q;
    //                 p2 = p2->next;
    //             }
    //         }
    //
    //         if (p1 && !p2) {
    //             t->next = p1;
    //         } else if (p2 && !p1) {
    //             t->next = p2;
    //         }
    //
    //         return head;
    //     }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main() {
    ListNode* list1, * list2, * ans;
    vector<int> arr1, arr2;
    arr1 = { 1,2,4 };
    arr2 = { 1,3,4 };
    Solution sl;
    list1 = createLinkList(arr1);
    list2 = createLinkList(arr2);

    // ListNode* t1 = list1, * t2 = list2;
    // while (t1) {
    //     cout << t1->val << " ";
    //     t1 = t1->next;
    // }
    // cout << endl;
    // while (t2) {
    //     cout << t2->val << " ";
    //     t2 = t2->next;
    // }
    // cout << endl;

    ans = sl.mergeTwoLists(list1, list2);

    ListNode* t = ans;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;


    return 0;
}
