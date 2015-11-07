// Subtree

#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = left->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isEqual(TreeNode *T1, TreeNode *T2) {
        int status = 0;

        status |= (T1 == NULL ? 1 : 0);
        status |= ((T2 == NULL ? 1 : 0) << 1);

        switch (status) {
        case 0:
            if (T1->val == T2->val) {
                return isEqual(T1->left, T2->left)
                    && isEqual(T1->right, T2->right);
            } else {
                return false;
            }
            break;

        case 1:
        case 2:
            return false;
            break;

        case 3:
            return true;
            break;

        }

        return false;
    }

    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL) {
            return true;
        }

        if (T1 == NULL) {
            return false;
        }

        if (isEqual(T1, T2)) {
            return true;
        } else {
            return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
        }
    }
};
