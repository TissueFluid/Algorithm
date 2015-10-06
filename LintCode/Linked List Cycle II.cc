// Linked List Cycle II

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

ListNode *detectCycle(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next && slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    fast = head;
    slow = slow->next;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}
