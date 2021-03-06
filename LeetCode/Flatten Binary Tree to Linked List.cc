// Flatten Binary Tree to Linked List

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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode *p = root->left;

        if (p) {
            while (p->right) {
                p = p->right;
            }

            p->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
