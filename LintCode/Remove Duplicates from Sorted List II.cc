// Remove Duplicates from Sorted List II

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void *deleteNextNode(ListNode *node) {
    ListNode *tmp = node->next;
    node->next = node->next->next;
    delete tmp;
}

ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL) {
        return head;
    }

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    for (auto p = dummy; p->next && p->next->next; ) {
        if (p->next->val == p->next->next->val) {
            for (auto q = p->next->next; q && q->val == p->next->val; q = q->next) {
                deleteNextNode(p->next);
            }
            deleteNextNode(p);
        } else {
            p = p->next;
        }
    }

    ListNode *ret = dummy->next;
    delete dummy;

    return ret;
}
