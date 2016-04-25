// Path Sum II

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void helper(TreeNode *root, int sum, vector<vector<int> > &result) {
        static vector<int> tmp;
        tmp.push_back(root->val);
        sum -= root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == 0) {
                result.push_back(tmp);
            }
        } else {
            if (root->left) {
                helper(root->left, sum, result);
            }

            if (root->right) {
                helper(root->right, sum, result);
            }
        }

        tmp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int> > result;

        helper(root, sum, result);

        return result;
    }
};
