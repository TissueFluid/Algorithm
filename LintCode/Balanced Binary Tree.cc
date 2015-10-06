// Balanced Binary Tree

#include <iostream>
#include <algorithm>
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

bool isBalanced(TreeNode *root, int &depth) {
    if (root == NULL) {
        depth = 0;
        return true;
    }

    int depthLeft;
    int depthRight;

    if (isBalanced(root->left, depthLeft) == false) {
        return false;
    }

    if (isBalanced(root->left, depthRight) == false) {
        return false;
    }

    if (!(depthLeft == depthRight + 1
          || depthRight == depthLeft + 1
          || depthRight == depthLeft)) {
        return false;
    }

    depth = 1 + max(depthLeft, depthRight);
    return true;
}

bool isBalanced(TreeNode *root) {
    int depth;
    return isBalanced(root, depth);
}
