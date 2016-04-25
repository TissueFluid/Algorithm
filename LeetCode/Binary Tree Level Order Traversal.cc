// Binary Tree Level Order Traversal

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<vector<int> > result;
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty()) {
            vector<int> tmp;
            const int qsize = q.size();

            for (int i = 0; i < qsize; ++i) {
                auto front = q.front();
                q.pop();

                tmp.push_back(front->val);
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }

            result.push_back(tmp);
        }

        return result;
    }
};
