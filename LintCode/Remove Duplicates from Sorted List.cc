/*
 * Remove Duplicates from Sorted List
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


#include <iostream>
using namespace std;


class ListNode {
public:
    int val;
    ListNode * next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL) {
        return head;
    }

    int last = head->val;

    for (ListNode * p = head; p->next != NULL; ) {
        if (p->next->val == last) {
            ListNode * tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        } else {
            last = p->next->val;
            p = p->next;
        }
    }

    return head;
}
