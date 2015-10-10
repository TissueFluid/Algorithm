// Minimum Depth of Binary Tree

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int status = 0;
    int ret = 0;

    status |= (root->right != NULL ? 1 : 0);
    status |= (root->left != NULL ? 1<<1 : 0);

    switch (status) {
    case 0:
        ret = 1;
        break;
    case 1:
        ret = 1 + minDepth(root->right);
        break;
    case 2:
        ret = 1 + minDepth(root->left);
        break;
    case 3:
        ret = 1 + min(minDepth(root->left), minDepth(root->right));
    }

    return ret;
}
