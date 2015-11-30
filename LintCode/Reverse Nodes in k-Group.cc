// Reverse Nodes in k-Group

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *reverse(ListNode *start, int k) {
        ListNode *p = start;

        for (int i = 0; i < k; ++i) {
            if (p == NULL) {
                return start;
            }
            p = p->next;
        }

        ListNode *dummy = new ListNode(0);

        p = start;
        for (int i = 0; i < k && p; ++i) {
            auto next = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = next;
        }

        start->next = p;

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
public:
    /**
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0);

        dummy->next = head;

        auto p = dummy;

        while (p->next) {
            auto tmp = p->next;
            p->next = reverse(p->next, k);
            p = tmp;
        }

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};
