// Delete Node in the Middle of Singly Linked List
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

class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        if (node == NULL) {
            return;
        }

        ListNode *tmp = node->next;

        node->val = tmp->val;
        node->next = tmp->next;

        delete tmp;
    }
};
