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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        stack<TreeNode *> stk;
        auto current = root;
        auto previous= root;

        while (!stk.empty() || current != NULL) {
            if (current) {
                stk.push(current);
                current = current->left;
            } else {
                auto top = stk.top();

                if (previous == top->right) {
                    result.push_back(top->val);
                    stk.pop();
                } else {
                    current = top->right;
                }
            }

            previous = current;
        }

        return result;
    }
};
