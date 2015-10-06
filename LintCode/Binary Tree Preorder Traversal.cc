// Binary Tree Preorder Traversal

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;

    if (root) {
        stack<TreeNode *> s;

        s.push(root);
        while (!s.empty()) {
            TreeNode *tmp = s.top();
            s.pop();
            ret.push_back(tmp->val);
            if (tmp->right) {
                s.push(tmp->right);
            }
            if (tmp->left) {
                s.push(tmp->left);
            }
        }
    }

    return ret;
}
