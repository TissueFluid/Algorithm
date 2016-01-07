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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        stack<TreeNode *> s;
        auto current = root;

        while (!s.empty() || current != NULL) {
            if (current) {
                s.push(current);
                current = current->left;
            } else {
                auto top = s.top();
                s.pop();
                result.push_back(top->val);
                current = top->right;
            }
        }

        return result;
    }
};
