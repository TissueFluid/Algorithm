// Construct Binary Tree from Inorder and Postorder Traversal

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &inorder, int in_start, int in_end,
                    vector<int> &postorder, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) {
        return NULL;
    }

    int position;
    for (position = in_start; position <= in_end; ++position) {
        if (inorder[position] == postorder[post_end]) {
            break;
        }
    }

    if (position > in_end) {
        return NULL;
    }

    TreeNode *node = new TreeNode(postorder[post_end]);

    node->left = buildTree(
        inorder, in_start, position - 1,
        postorder, post_start, post_start + position - in_start - 1);
    node->right = buildTree(
        inorder, position + 1, in_end,
        postorder, post_start + position - in_start, post_end - 1);

    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int size_inorder = inorder.size();
    int size_postorder = postorder.size();

    if (size_inorder == 0
        || size_postorder == 0
        || size_inorder != size_postorder) {
        return NULL;
    }

    return buildTree(inorder, 0, size_inorder - 1,
                     postorder, 0, size_postorder - 1);
}
