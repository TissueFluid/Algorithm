// Remove Duplicates from Sorted List

#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        auto p = head;

        while (p->next) {
            if (p->next->val != p->val) {
                p = p->next;
            } else {
                auto toBeDeleted = p->next;
                p->next = p->next->next;
                delete toBeDeleted;
            }
        }

        return head;
    }
};
