#include "../../LeetCode.h"
#include "../../LeetCodeLList.h"

using namespace std;

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret, * p1, * p2, * t;
        p1 = l1; p2 = l2;
        // 为头结点赋值
        if (p1->val < p2->val) {
            ret = p1;
            p1 = p1->next;
        } else {
            ret = p2;
            p2 = p2->next;
        }
        ret->next = nullptr;
        t = ret;
        // 当 l1 l2 均非空时
        while (p1 || p2) {
            // 当 l1 非空 l2 为空时
            if (p1 && !p2) {
                t->next = p1;
                break;
                // 当 l2 非空 l1 为空时
            } else if (p2 && !p1) {
                t->next = p2;
                break;
                // 当 l1 l2 均非空时
            } else {
                // 若 l1元素 小于 l2元素 l1元素
                if (p1->val < p2->val) {
                    t->next = p1;
                    p1 = p1->next == nullptr ? nullptr : p1->next;
                    // 若 l1元素 小于 l2元素 l1元素
                } else {
                    t->next = p2;
                    p2 = p2->next == nullptr ? nullptr : p2->next;
                }
                t = t->next;
                t->next = nullptr;
            }
        }

        return ret;
    }
public:
    ListNode* mergeKLists(vector<ListNode*> lists) {
        ListNode* ret, * t;
        // 若当前数组为空
        if (lists.size() == 0) {
            return nullptr;
        }
        // 若当前数组仅有1链表
        if (lists.size() == 0) {
            return nullptr;
        }
        // 去除数组中为空的链表
        vector<ListNode*>::iterator it = lists.begin();
        for (; it != lists.end(); it++) {
            if (*it == nullptr) {
                lists.erase(it);
                it--;
            }
        }
        ret = lists[0];
        t = ret;
        for (int i = 1; i < lists.size(); i++) {
            ret = mergeTwoLists(ret, lists[i]);
        }

        return ret;
    }
};

int main() {
    Solution sl;
    vector<vector<int>> arr = { {1,4,5},{1,3,4},{2,6} };
    vector<ListNode*> lists = createLinkList(arr);
    // 测试
    // for (ListNode* it : lists) {
    //     ListNode* t = it;
    //     while (t) {
    //         cout << t->val << " ";
    //         t = t->next;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    ListNode* ans = sl.mergeKLists(lists);
    ListNode* t = ans;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}
