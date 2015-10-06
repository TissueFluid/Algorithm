// Insert Node in a Binary Search Tree

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertNode(TreeNode* root, TreeNode* node) {
    if (root == NULL) {
        return node;
    }

    TreeNode *p = root;

    while (p) {
        if (node->val < p->val) {
            if (p->left == NULL) {
                p->left = node;
                break;
            } else {
                p = p->left;
            }
        } else {
            if (p->right == NULL) {
                p->right = node;
                break;
            } else {
                p = p->right;
            }
        }
    }

    return root;
}
