// Nth to Last Node in List

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

ListNode *nthToLast(ListNode *head, int n) {
    ListNode *p = NULL;
    int size = 0;

    for (p = head; p; p = p->next) {
        size++;
    }

    if (size < n) {
        return NULL;
    }

    p = head;
    for (int i = 0; i < size - n; i++) {
        p = p->next;
    }

    return p;
}
