// Balanced Binary Tree
#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Helper {
    int depth;
    bool isBalanced;
};

class Solution {
    Helper helper(TreeNode *root) {
        if (root == NULL) {
            return {0, true};
        }

        auto left = helper(root->left);

        if (!left.isBalanced) {
            return {0, false};
        }

        auto right = helper(root->right);

        if (!right.isBalanced) {
            return {0, false};
        }

        if (abs(left.depth - right.depth) > 1) {
            return {0, false};
        }

        return {1 + max(left.depth, right.depth), true};
    }
public:
    bool isBalanced(TreeNode* root) {
        auto result = helper(root);

        return result.isBalanced;
    }
};
