#include "../LeetCode.h"
#include "../LeetCodeLList.h"

using namespace std;

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret, * p1, * p2, * t;
        p1 = l1; p2 = l2;
        if (p1->val < p2->val) {
            ret = p1;
            p1 = p1->next;
        } else {
            ret = p2;
            p2 = p2->next;
        }
        t = ret;
        // 当 l1 l2 不全为空链表时
        while (p1 || p2) {
            // 情况一：l1 不为空，l2 为空
            if (p1 && !p2) {
                t->next = p1;
                break;
                // 情况二：l2 不为空，l1 为空
            } else if (p2 && !p1) {
                t->next = p2;
                break;
                // 情况三：l1 l2 均为空
            } else if (!p1 && !p2) {
                break;
                // 情况四：l1 l2 均不为空
            } else {
                if (p1->val < p2->val) {
                    t->next = p1;
                    if (!p1->next) {
                        p1 = nullptr;
                    } else {
                        p1 = p1->next;
                    }
                } else {
                    t->next = p2;
                    if (!p2->next) {
                        p2 = nullptr;
                    } else {
                        p2 = p2->next;
                    }
                }
                t = t->next;
                t->next = nullptr;
            }
        }

        return ret;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret;
        // 链表数组中没有链表
        if (lists.size() == 0) {
            return nullptr;
        }
        // 数组中只有一个链表
        if (lists.size() == 1) {
            return lists[0];
        }
        // 删除数组中的空链表 - 被 chatgpt 纠正
        vector<ListNode*>::iterator it = lists.begin();
        while (it != lists.end()) {
            if (*it == nullptr) {
                lists.erase(it);
            } else {
                it++;
            }
        }
        if (lists.size() == 0) {
            return nullptr;
        }

        it = lists.begin();
        it++;
        ret = lists[0];
        for (; it != lists.end(); it++) {
            ret = mergeTwoLists(ret, *it);
        }

        return ret;
    }
};

int main() {
    Solution sl;
    vector<vector<int>> arr = { {-2,-1,-1,-1},{} };
    vector<ListNode*> lists;
    lists = createLinkList(arr);

    for (ListNode* it : lists) {
        ListNode* t = it;
        while (t) {
            cout << t->val << " ";
            t = t->next;
        }
        cout << endl;
    }

    ListNode* ans = sl.mergeKLists(lists);
    ListNode* t = ans;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}
