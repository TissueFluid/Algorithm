// Remove Node in Binary Search Tree

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *removeMaxNode(TreeNode *node, int &max) {
    if (node == NULL) {
        return NULL;
    }

    TreeNode *ret = node;

    TreeNode *previous = NULL;

    while (node->right) {
        previous = node;
        node = node->right;
    }

    max = node->val;

    if (previous == NULL) {
        ret = node->left;
    } else {
        previous->right = node->left;
    }
    delete node;

    return ret;
}

TreeNode *removeNode(TreeNode *node) {
    int status = 0;

    status |= (node->right ? 1 : 0);
    status |= (node->left ? (1<<1) : 0);

    TreeNode *ret[] = {
        NULL,
        node->right,
        node->left,
        node
    };

    switch (status) {
    case 0:
    case 1:
    case 2:
        delete node;
        break;
    case 3:
        node->left = removeMaxNode(node->left, node->val);
        break;
    }

    return ret[status];
}

TreeNode *removeNode(TreeNode *root, int value) {
    TreeNode *previous = NULL;
    TreeNode *ret = root;

    while (root) {
        if (value < root->val) {
            previous = root;
            root = root->left;
        } else if (value > root->val) {
            previous = root;
            root = root->right;
        } else {
            if (previous == NULL) {
                return removeNode(root);
            } else {
                if (previous->left == root) {
                    previous->left = removeNode(root);
                } else {
                    previous->right = removeNode(root);
                }
            }
            break;
        }
    }

    return ret;
}
