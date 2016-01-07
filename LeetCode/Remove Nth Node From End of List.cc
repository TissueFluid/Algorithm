#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) {
            return NULL;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        auto p = dummy;

        for (int i = 0; i < n; ++i) {
            p = p->next;
            if (p == NULL) {
                return NULL;
            }
        }

        auto q = dummy;

        while (p->next) {
            p = p->next;
            q = q->next;
        }

        q->next = q->next->next;

        auto ret = dummy->next;
        delete dummy;
        return ret;
    }
};
