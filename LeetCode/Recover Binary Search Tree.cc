// Recover Binary Search Tree

#include <cstdio>
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
    stack<TreeNode *> stk;
    TreeNode *current;

    void init(TreeNode *root) {
        current = root;
    }

    TreeNode *nextNode() {
        if (current == NULL && stk.empty()) {
            return NULL;
        }

        while (current) {
            stk.push(current);
            current = current->left;
        }

        auto top = stk.top();
        stk.pop();
        current = top->right;
        return top;
    }
public:
    void recoverTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        init(root);

        auto previous = nextNode();
        TreeNode *p;
        TreeNode *candidate1 = NULL;
        TreeNode *candidate2 = NULL;

        while ((p = nextNode()) != NULL) {
            if (p->val < previous->val) {
                candidate1 = previous;
                candidate2 = p;
                break;
            }
            previous = p;
        }
        previous = p;

        while ((p = nextNode()) != NULL) {
            if (p->val < previous->val) {
                candidate2 = p;
                break;
            }
        }

        if (candidate1 && candidate2) {
            swap(candidate1->val, candidate2->val);
        }
    }
};
