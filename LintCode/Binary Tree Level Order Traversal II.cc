// Binary Tree Level Order Traversal II

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > result;
    stack<vector<int> > inversed_result;

    if (root == NULL) {
        return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; ++i) {
            TreeNode *top = q.front();
            level.push_back(top->val);
            if (top->left) {
                q.push(top->left);
            }
            if (top->right) {
                q.push(top->right);
            }
            q.pop();
        }

        inversed_result.push(level);
    }

    while (!inversed_result.empty()) {
        result.push_back(inversed_result.top());
        inversed_result.pop();
    }

    return result;
}
