// Maximum Depth of Binary Tree

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

int maxDepth(TreeNode *root) {
    if (root) {
        return 1 + max(maxDepth(root->left), (maxDepth(root->right)));
    } else {
        return 0;
    }
}
