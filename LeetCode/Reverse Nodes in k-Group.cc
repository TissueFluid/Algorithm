// Reverse Nodes in k-Group

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *reverseAfter(ListNode *prevNode, int k) {
        ListNode *cursor = prevNode->next;

        int i;

        for (i = 0; i < k && cursor; ++i) {
            cursor = cursor->next;
        }

        if (i != k) {
            return NULL;
        }

        auto nextFirst = cursor;
        auto tail = prevNode->next;
        cursor = prevNode->next;

        for (i = 0; i < k; ++i) {
            auto next = cursor->next;
            cursor->next = prevNode->next;
            prevNode->next = cursor;
            cursor = next;
        }

        tail->next = nextFirst;

        return tail;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        for (auto p = dummy; p;) {
            p = reverseAfter(p, k);
        }

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};
