// Convert Binary Search Tree to Doubly Linked List

#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        DoublyListNode *dummy = new DoublyListNode(0);
        DoublyListNode *last = dummy;

        stack<TreeNode *> s;
        s.push(root);

        TreeNode *p = root;

        while (p || !s.empty()) {
            while (p != NULL) {
                s.push(p);
                p = p->left;
            }

            p = s.top();
            s.pop();

            last->next = new DoublyListNode(p->val);
            last->next->prev = last;
            last = last->next;

            p = p->right;
        }

        DoublyListNode *ret = dummy->next;
        ret->prev = NULL;
        delete dummy;

        return ret;
    }
};
