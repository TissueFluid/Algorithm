// Sum Root to Leaf Numbers

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
protected:
  void helper(TreeNode *root, int &result) {
    static int tmp = 0;

    tmp *= 10;
    tmp += root->val;

    if (root->left == nullptr && root->right == nullptr) {
      result += tmp;
    } else {
      if (root->left) {
        helper(root->left, result);
      }
      if (root->right) {
        helper(root->right, result);
      }
    }

    tmp /= 10;
  }
public:
  int sumNumbers(TreeNode *root) {
    int result = 0;

    if (root == nullptr) {
      return result;
    }

    helper(root, result);

    return result;
  }
};
