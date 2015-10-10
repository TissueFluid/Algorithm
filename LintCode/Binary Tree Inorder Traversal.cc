// Binary Tree Inorder Traversal

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;

    if (root == NULL) {
        return result;
    }

    stack<TreeNode *> s;

    while (root || !s.empty()) {
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            result.push_back(root->val);
            root = root->right;
        }
    }

    return result;
}
