// Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        auto p = headA;
        auto q = headB;

        while (p && q) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }

        ListNode *longList, *shortList;

        if (p) {
            longList = headA;
            shortList = headB;
        } else {
            longList = headB;
            shortList = headA;
        }

        int diff = 0;

        while (p) {
            p = p->next;
            diff++;
        }

        while (q) {
            q = q->next;
            diff++;
        }

        if (diff == 0) {
            return NULL;
        }

        while (diff--) {
            longList = longList->next;
        }

        while (longList) {
            if (longList == shortList) {
                return longList;
            }
            longList = longList->next;
            shortList = shortList->next;
        }

        return NULL;
    }
};
