#include <cstdlib>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *last = dummy;

        auto p = l1;
        auto q = l2;
        int c = 0;

        while (p && q) {
            last->next = new ListNode(p->val + q->val + c);
            last = last->next;
            if (last->val >= 10) {
                c = 1;
                last->val -= 10;
            } else {
                c = 0;
            }
            p = p->next;
            q = q->next;
        }

        vector<ListNode *> ptrs({p, q});

        for (auto &ptr : ptrs) {
            while (ptr) {
                last->next = new ListNode(ptr->val + c);
                last = last->next;
                if (last->val >= 10) {
                    c = 1;
                    last->val -= 10;
                } else {
                    c = 0;
                }
                ptr = ptr->next;
            }
        }

        if (c == 1) {
            last->next = new ListNode(1);
        }

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};
