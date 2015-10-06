// Reorder List

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

void reorderList(ListNode *head) {
    ListNode *dummy = new ListNode(0);

    dummy->next = head;

    ListNode *p = dummy;
    ListNode *q = dummy;

    while (q->next) {
        p = p->next;
        q = q->next;
        if (q->next) {
            q = q->next;
        }
    }

    ListNode *reverse_start = p->next;
    p->next = NULL;
    dummy->next = NULL;

    while (reverse_start) {
        ListNode *tmp = reverse_start->next;
        reverse_start->next = dummy->next;
        dummy->next = reverse_start;
        reverse_start = tmp;
    }

    p = head;
    q = dummy->next;
    while (q) {
        ListNode *tmp = q->next;
        q->next = p->next;
        p->next = q;
        q = tmp;
        p = p->next->next;
    }

    delete dummy;
}
