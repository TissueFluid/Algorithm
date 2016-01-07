#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        stack<TreeNode *> stk;

        stk.push(root);

        while (!stk.empty()) {
            auto top = stk.top();
            stk.pop();

            result.push_back(top->val);
            if (top->right) {
                stk.push(top->right);
            }
            if (top->left) {
                stk.push(top->left);
            }
        }

        return result;
    }
};
