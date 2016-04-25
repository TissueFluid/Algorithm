/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        ListNode *last = dummy;

        ListNode *p = head;

        while (p && p->next) {
            if (p->val != p->next->val) {
                last->next = p;
                last = p;
                p = p->next;
            } else {
                auto same = p->val;
                do {
                    auto tmp = p;
                    p = p->next;
                    delete tmp;
                } while (p && p->val == same);
            }
        }

        last->next = p;

        auto ret = dummy->next;
        return ret;
    }
};
