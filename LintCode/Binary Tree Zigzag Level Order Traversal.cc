// Binary Tree Zigzag Level Order Traversal

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    bool leftToRight = true;
    vector<vector<int> > result;

    if (root == NULL) {
        return result;
    }

    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        vector<int> level;
        TreeNode *top;

        if (leftToRight) {
            while (!s1.empty()) {
                top = s1.top();
                if (top->left) {
                    s2.push(top->left);
                }
                if (top->right) {
                    s2.push(top->right);
                }
                s1.pop();
                level.push_back(top->val);
            }
        } else {
            while (!s2.empty()) {
                top = s2.top();
                if (top->right) {
                    s1.push(top->right);
                }
                if (top->left) {
                    s1.push(top->left);
                }
                s2.pop();
                level.push_back(top->val);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(level);
    }

    return result;
}

int main() {
    zigzagLevelOrder(NULL);
    return 0;
}
