// Binary Search Tree Iterator

#include <iostream>
#include <stack>
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

class BSTIterator {
private:
    stack<TreeNode *> s;
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        auto p = root;
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return !s.empty();
    }

    //@return: return next node
    TreeNode* next() {
        auto top = s.top();
        s.pop();

        auto p = top->right;
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }

        return top;
    }
};
