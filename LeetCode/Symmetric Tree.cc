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
    bool isSame(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        }

        if (p == NULL || q == NULL) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return (isSame(p->left, q->right) && isSame(p->right, q->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return isSame(root->left, root->right);
    }
};
