// Insertion Sort List

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

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        for (auto p = head; p->next != NULL; p = p->next) {
            auto min = p;
            for (auto q = p->next; q != NULL; q = q->next) {
                if (q->val < min->val) {
                    min = q;
                }
            }
            if (min != p) {
                int tmp = min->val;
                min->val = p->val;
                p->val = tmp;
            }
        }

        return head;
    }
};
