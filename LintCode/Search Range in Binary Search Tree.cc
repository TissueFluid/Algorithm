// Search Range in Binary Search Tree

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> searchRange(TreeNode* root, int k1, int k2) {
    vector<int> result;
    stack<TreeNode *> s;

    if (root == NULL) {
        return result;
    }

    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        } else {
            TreeNode *top = s.top();
            if (k1 <= top->val && top->val <= k2) {
                result.push_back(top->val);
            }
            s.pop();
            root = top->right;
        }
    }

    return result;
}
