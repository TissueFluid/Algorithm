// Partition List

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyLeft = new ListNode(0);
        ListNode *dummyRight = new ListNode(0);
        auto p = dummyLeft;
        auto q = dummyRight;

        while (head) {
            if (head->val < x) {
                p->next = head;
                p = head;
            } else {
                q->next = head;
                q = head;
            }
            head = head->next;
        }

        p->next = dummyRight->next;
        q->next = NULL;

        auto ret  = dummyLeft->next;

        delete dummyLeft;
        delete dummyRight;

        return ret;
    }
};
