// Binary Tree Level Order Traversal

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > result;

    if (root == NULL) {
        return result;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> level;
        auto size = q.size();

        for (unsigned i = 0; i < size; ++i) {
            TreeNode *front = q.front();
            level.push_back(front->val);
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
            q.pop();
        }

        result.push_back(level);
    }

    return result;
}
