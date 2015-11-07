// Lowest Common Ancestor

#include <iostream>
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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (root == NULL || root == A || root == B) {
            return root;
        }

        auto left = lowestCommonAncestor(root->left, A, B);
        auto right = lowestCommonAncestor(root->right, A, B);

        int status = 0;
        status |= (left != NULL);
        status |= (right != NULL) << 1;

        switch (status) {
        case 0:
            return NULL;
        case 1:
            return left;
        case 2:
            return right;
        case 3:
            return root;
        }

        return NULL;
    }
};
