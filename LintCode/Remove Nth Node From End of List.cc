/*
 * Remove Nth Node From End of List
 *   Linked List
 *
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * };
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

ListNode *removeNthFromEnd(ListNode *head, int n) {
    int size = 0;

    for (auto p = head; p != NULL; p = p->next) {
        size++;
    }

    if (size == n) {
        auto ret = head->next;
        free(head);
        return ret;
    }

    auto p = head;
    for (auto i = 0; i < size - n - 1; ++i) {
        p = p->next;
    }
    auto tmp = p->next;
    p->next = tmp->next;
    free(tmp);

    return head;
}
