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
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto last = dummy;

        for (auto p = head; p;) {
            if (p->next) {
                auto nextp = p->next->next;
                last->next = p->next;
                last = last->next;
                last->next = p;
                last = last->next;
                p = nextp;
            } else {
                last->next = p;
                last = last->next;
                break;
            }
        }
        last->next = NULL;

        auto ret = dummy->next;
        delete dummy;
        return ret;
    }
};
