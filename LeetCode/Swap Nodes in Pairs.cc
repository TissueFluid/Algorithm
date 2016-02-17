// Swap Nodes in Pairs

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (head) {
            ListNode *first = head;
            ListNode *second = first->next;
            if (second) {
                head = second->next;
                second->next = first;
                tail->next = second;
                tail = first;
            } else {
                tail->next = first;
                tail = first;
                break;
            }
        }
        tail->next = NULL;

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};
