// Minimum Depth of Binary Tree

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int helper(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        if (root->left == nullptr) {
            return 1 + helper(root->right);
        }

        if (root->right == nullptr) {
            return 1 + helper(root->left);
        }

        return 1 + min(helper(root->left), helper(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return helper(root);
    }
};
