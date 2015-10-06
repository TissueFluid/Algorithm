// Convert Sorted List to Binary Search Tree

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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

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

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

TreeNode *convert(ListNode *&head, int size) {
    if (size <= 0) {
        return NULL;
    }

    TreeNode *root = new TreeNode(0);

    root->left = convert(head, size / 2);
    root->val = head->val;
    head = head->next;
    root->right = convert(head, size - 1 - size / 2);

    return root;
}

TreeNode *sortedListToBST(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }


    int size = 0;
    for (ListNode *p = head; p != NULL; p = p->next) {
        size++;
    }

    return convert(head, size);
}
