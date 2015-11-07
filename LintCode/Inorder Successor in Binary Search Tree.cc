// Inorder Successor in Binary Search Tree

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) {
            return NULL;
        }

        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }

        TreeNode *pre = NULL;

        while (root) {
            if (root == p) {
                return pre;
            } else if (p->val < root->val) {
                pre = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return NULL;
    }
};
