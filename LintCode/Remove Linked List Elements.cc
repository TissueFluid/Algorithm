// Remove Linked List Elements

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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummy = new ListNode(0);

        dummy->next = head;

        for (auto p = dummy; p->next;) {
            if (p->next->val == val) {
                ListNode *toBeDeleted = p->next;
                p->next = toBeDeleted->next;
                delete toBeDeleted;
            } else {
                p = p->next;
            }
        }

        auto ret = dummy->next;
        delete dummy;

        return ret;
    }
};


int main() {

    return 0;
}
