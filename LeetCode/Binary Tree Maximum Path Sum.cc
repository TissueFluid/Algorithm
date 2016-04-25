// Binary Tree Maximum Path Sum

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
protected:
  int helper(TreeNode *root, int &result) {
    if (root == NULL) {
      return 0;
    }

    auto leftMax = max(helper(root->left, result), 0);
    auto rightMax = max(helper(root->right, result), 0);

    result = max(result, root->val + leftMax + rightMax);

    return root->val + max(leftMax, rightMax);
  }
public:
  int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    helper(root, result);
    return result;
  }
};
