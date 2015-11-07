// Binary Tree Maximum Path Sum - DP

#include <iostream>
#include <vector>
#include <limits>
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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root, int &result) {
        if (root == NULL) {
            return 0;
        }

        int leftMaxSum = max(0, maxPathSum(root->left, result));
        int rightMaxSum = max(0, maxPathSum(root->right, result));

        result = max(result, root->val + leftMaxSum + rightMaxSum);

        return (root->val + max(leftMaxSum, rightMaxSum));
    }
    int maxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int result = numeric_limits<int>::min();
        maxPathSum(root, result);

        return result;
    }
};
