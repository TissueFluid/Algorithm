// Palindrome Linked List

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *findBeforeMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;

        while (head) {
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }
public:
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }

        auto beforeMiddle = findBeforeMiddle(head);

        beforeMiddle->next = reverse(beforeMiddle->next);

        auto p1 = head;
        auto p2 = beforeMiddle->next;

        while (p2 && p1->val == p2->val) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2 == NULL;
    }
};
