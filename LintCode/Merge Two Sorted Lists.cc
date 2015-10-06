/*
  Merge Two Sorted Lists
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
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == NULL) {
        return l2;
    }

    if (l2 == NULL) {
        return l1;
    }

    ListNode * head = new ListNode(0);
    ListNode * last = NULL;

    for (last = head; l1 && l2; last = last->next) {
        if (l1->val < l2->val) {
            last->next = l1;
            l1 = l1->next;
        } else {
            last->next = l2;
            l2 = l2->next;
        }
    }
    if (l1) {
        last->next = l1;
    } else {
        last->next = l2;
    }

    ListNode * ret = head->next;
    delete head;
    return ret;
}
