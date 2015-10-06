// Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL) {
        return head;
    }

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    int size = 0;
    ListNode *last;
    for (last = dummy; last->next; last = last->next) {
        size++;
    }
    k %= size;
    if (k == 0) {
        return head;
    }

    ListNode *p = dummy;
    for (int i = 0; i < size - k; ++i) {
        p = p->next;
    }

    dummy->next = p->next;
    p->next = NULL;
    last->next = head;

    ListNode *ret = dummy->next;

    delete dummy;

    return ret;
}
