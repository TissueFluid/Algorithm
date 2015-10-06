// Construct Binary Tree from Preorder and Inorder Traversal

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &preorder, int pre_start, int pre_end,
                    vector<int> &inorder, int in_start, int in_end) {
    TreeNode *node = new TreeNode(preorder[pre_start]);

    if (pre_start > pre_end || in_start > in_end) {
        return NULL;
    }

    int position;
    for (position = in_start; position <= in_end; ++position) {
        if (preorder[pre_start] == inorder[position]) {
            break;
        }
    }

    node->left = buildTree(
        preorder, pre_start + 1, pre_start + position - in_start,
        inorder, in_start, position - 1);

    node->right = buildTree(
        preorder, pre_start + position - in_start + 1, pre_end,
        inorder, position + 1, in_end);

    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int size_preorder = preorder.size();
    int size_inorder = inorder.size();

    if (size_preorder != size_inorder
        || size_preorder == 0
        || size_inorder == 0) {
        return NULL;
    }

    return buildTree(preorder, 0, size_preorder - 1,
                     inorder, 0, size_inorder - 1);
}
