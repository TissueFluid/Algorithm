/*
 * Partition List
 *   Two points
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

ListNode *partition(ListNode *head, int x) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode *left_head = new ListNode(0);
    ListNode *right_head = new ListNode(0);
    ListNode *left_last = left_head;
    ListNode *right_last = right_head;

    while (head) {
        if (head->val < x) {
            left_last->next = head;
            left_last = left_last->next;
        } else {
            right_last->next = head;
            right_last = right_last->next;
        }
        head = head->next;
    }

    right_last->next = NULL;
    left_last->next = right_head->next;
    ListNode *ret = left_head->next;

    delete left_head;
    delete right_head;

    return ret;
}
