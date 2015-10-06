// Add two numbers

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addLists(ListNode *l1, ListNode *l2) {
    int c = 0;

    ListNode *dummy = new ListNode(0);
    ListNode *last = dummy;

    while (l1 && l2) {
        int tmp = l1->val + l2->val + c;
        c = tmp / 10;
        tmp %= 10;
        last->next = new ListNode(tmp);
        last = last->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    ListNode *remain = NULL;
    if (l1) {
        remain = l1;
    }
    if (l2) {
        remain = l2;
    }

    while (remain) {
        int tmp = remain->val + c;
        c = tmp / 10;
        tmp %= 10;
        last->next = new ListNode(tmp);
        last = last->next;
        remain = remain->next;
    }

    if (c) {
        last->next = new ListNode(c);
    }

    ListNode *ret = dummy->next;
    delete dummy;

    return ret;
}
