// Flatten Binary Tree to Linked List

#include <iostream>
using namespace std;

/**
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

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        auto left = root->left;
        auto right = root->right;

        root->left = NULL;
        root->right = left;

        auto p = root;
        for (; p->right; p = p->right) {
            if (p->right == NULL) {
                break;
            }
        }

        p->right = right;
    }
};
