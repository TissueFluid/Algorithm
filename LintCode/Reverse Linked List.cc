// Reverse Linked List

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

ListNode *reverse(ListNode *head) {
    ListNode *dummy = new ListNode(0);

    while (head) {
        ListNode *tmp = head->next;
        head->next = dummy->next;
        dummy->next = head;
        head = tmp;
    }

    ListNode *ret = dummy->next;
    delete dummy;

    return ret;
}
