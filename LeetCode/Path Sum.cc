// Path Sum
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool helper(TreeNode *root, int sum) {
        sum -= root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return sum == 0;
        }

        if (root->left == nullptr) {
            return helper(root->right, sum);
        }

        if (root->right == nullptr) {
            return helper(root->left, sum);
        }

        return helper(root->left, sum) || helper(root->right, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }

        return helper(root, sum);
    }
};
