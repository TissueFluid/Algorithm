// Linked List Cycle

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

bool hasCycle(ListNode *head) {
    ListNode *p = head;
    ListNode *q = head;

    while (q) {
        p = p->next;
        q = q->next;
        if (q) {
            q = q->next;
        }
        if (p == q && q) {
            return true;
        }
    }

    return false;
}
