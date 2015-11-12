// Unique Binary Search Trees II

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
private:
    void generateTrees(int start, int end,
                       vector<TreeNode *> &result) {
        if (start > end) {
            result.push_back(NULL);
            return;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode *> lefts;
            vector<TreeNode *> rights;

            generateTrees(start, i - 1, lefts);
            generateTrees(i + 1, end, rights);

            for (TreeNode *left : lefts) {
                for (TreeNode *right : rights) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
    }
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        generateTrees(1, n, result);

        return result;
    }
};
