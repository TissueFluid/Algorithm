// Reverse Linked List II

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

ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *before, *after, *start, *end;

    before = dummy;
    for (int i = 1; i < m; ++i) {
        before = before->next;
    }
    start = before->next;

    end = start;
    for (int i = 0; i < n - m; ++i) {
        end = end->next;
    }
    after = end->next;

    ListNode *p = start->next;
    for (int i = 0; i < n - m; ++i) {
        ListNode *tmp = p->next;
        p->next = before->next;
        before->next = p;
        p = tmp;
    }

    start->next = after;

    ListNode *ret = dummy->next;
    delete dummy;

    return ret;
}
