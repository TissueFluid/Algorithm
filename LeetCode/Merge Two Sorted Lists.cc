#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *last = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                l2 = l2->next;
            }
            last = last->next;
        }

        if (l1) {
            last->next = l1;
        }

        if (l2) {
            last->next = l2;
        }

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};
