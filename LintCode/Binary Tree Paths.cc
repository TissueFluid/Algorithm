#include <iostream>
#include <vector>
#include <string>
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
    string to_result(vector<int> &tmp) {
        const int size = tmp.size();
        string result = to_string(tmp[0]);

        for (int i = 1; i < size; ++i) {
            result += ("->" + to_string(tmp[i]));
        }

        return result;
    }

    void path(TreeNode *root, vector<string> &result) {
        static vector<int> tmp;

        tmp.push_back(root->val);

        if (root->left || root->right) {
            if (root->left) {
                path(root->left, result);
            }
            if (root->right) {
                path(root->right, result);
            }
        } else {
            result.push_back(to_result(tmp));
        }

        tmp.pop_back();
    }
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        if (root != NULL) {
            path(root, result);
        }

        return result;
    }
};
