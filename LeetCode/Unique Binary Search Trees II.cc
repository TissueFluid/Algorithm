// Unique Binary Search Trees II

#include <cstdio>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
protected:
    void helper(int start, int end, vector<TreeNode *> &roots) {
        if (start > end) {
            roots.push_back(NULL);
            return;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode *> lefts;
            vector<TreeNode *> rights;

            helper(start, i - 1, lefts);
            helper(i + 1, end, rights);

            for (const auto &left : lefts) {
                for (const auto &right : rights) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    roots.push_back(root);
                }
            }
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> result;

        if (n == 0) {
            return result;
        }

        helper(1, n, result);

        return result;
    }
};
