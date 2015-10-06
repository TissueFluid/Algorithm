// Validate Binary Search Tree

#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool min_first = true;
bool max_first = true;

bool isValidBST(TreeNode *root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if ((min < root->val || (min == numeric_limits<int>::min() && min_first && !(min_first = false)))
        && ((root->val < max) || (max == numeric_limits<int>::max() && max_first && !(max_first = false)))) {
        if (isValidBST(root->left, min, root->val) == false) {
            return false;
        }
        if (isValidBST(root->right, root->val, max) == false) {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool isValidBST(TreeNode *root) {
    return isValidBST(root,
                      numeric_limits<int>::min(),
                      numeric_limits<int>::max());
}
