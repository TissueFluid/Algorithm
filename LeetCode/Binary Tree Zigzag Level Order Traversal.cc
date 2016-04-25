// Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;

        if (root == NULL) {
            return result;
        }

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

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

            if (!leftToRight) {
                reverse(tmp.begin(), tmp.end());
            }
            result.push_back(tmp);
            leftToRight = !leftToRight;
        }

        return result;
    }
};
