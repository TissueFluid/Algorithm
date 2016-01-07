//  Identical Binary Tree

#include <iostream>
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

class Solution {
public:
    /**
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) {
            return true;
        } else if (a && b) {
            return a->val == b->val
                && isIdentical(a->left, b->left)
                && isIdentical(a->right, b->right);
        } else {
            return false;
        }
    }
};
