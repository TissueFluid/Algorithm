// Convert Sorted Array to Binary Search Tree With Minimal Height

// mid = (start + end) / 2
// root <- a[mid]
// left <- a[(start + mid - 1) / 2]
// right

#include <iostream>
#include <vector>
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

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
private:
    TreeNode *helper (vector<int> &A, int start, int end) {
        if (start >= end) {
            return NULL;
        }

        int mid = (start + end) / 2;

        TreeNode *root = new TreeNode(A[mid]);

        root->left = helper(A, start, mid);
        root->right = helper(A, mid + 1, end);

        return root;
    }
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        return helper(A, 0, A.size());
    }
};
