// Validate Binary Search Tree

#include <stdio.h>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
protected:
    TreeNode *current;
    stack<TreeNode *> stk;
    TreeNode *getNextNode() {
        if (current == NULL && stk.empty()) {
            return NULL;
        }

        while (current) {
            stk.push(current);
            current = current->left;
        }

        auto ret = stk.top();
        stk.pop();
        current = ret->right;
        return ret;
    }

    void init(TreeNode *root) {
        current = root;
    }
public:
    bool isValidBST(TreeNode* root) {
        init(root);
        auto previous = getNextNode();
        TreeNode *p;

        while ((p = getNextNode()) != NULL) {
            if (p->val <= previous->val) {
                return false;
            }
            previous = p;
        }

        return true;
    }
};
