// Sort List
//   Merge sort or quick sort

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

ListNode *findMiddle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *merge(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(0);
    ListNode *last = dummy;

    while (left && right) {
        if (left->val < right->val) {
            last->next = left;
            left = left->next;
        } else {
            last->next = right;
            right = right->next;
        }
        last = last->next;
    }

    if (left) {
        last->next = left;
    }
    if (right) {
        last->next = right;
    }

    ListNode *ret = dummy->next;
    delete dummy;

    return ret;
}

ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode *mid = findMiddle(head);
    ListNode *right = sortList(mid->next);
    mid->next = NULL;
    ListNode *left = sortList(head);

    return merge(left, right);
}
