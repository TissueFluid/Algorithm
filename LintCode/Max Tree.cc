// Max Tree

// stack desc

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
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        const int size = A.size();

        if (size == 0) {
            return NULL;
        }

        vector<TreeNode *> s;

        for (int i = 0; i < size; ++i) {
            auto tmp = new TreeNode(A[i]);

            while (!s.empty() && s.back()->val < A[i]) {
                tmp->left = s.back();
                s.pop_back();
            }

            if (!s.empty()) {
                s.back()->right = tmp;
            }

            s.push_back(tmp);
        }

        return s[0];
    }
};
