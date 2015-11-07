// Binary Tree Postorder Traversal

#include <iostream>
#include <vector>
#include <stack>
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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        stack<TreeNode *> s;

        s.push(root);

        TreeNode *previous = root;

        while (!s.empty()) {
            auto top = s.top();

            if (previous == top->right) {
                result.push_back(top->val);
                s.pop();
            } else if (previous == top->left) {
                if (top->right) {
                    s.push(top->right);
                } else {
                    result.push_back(top->val);
                    s.pop();
                }
            } else if (top->left != NULL) {
                s.push(top->left);
            } else if (top->right != NULL) {
                s.push(top->right);
            } else {
                result.push_back(top->val);
                s.pop();
            }

            previous = top;
        }
    }
};
