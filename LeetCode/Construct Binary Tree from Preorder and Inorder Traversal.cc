// Construct Binary Tree from Preorder and Inorder Traversal

#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *helper(
        const vector<int> &preorder,
        const vector<int> &inorder,
        const int preStart,
        const int preEnd,
        const int inStart,
        const int inEnd,
        const unordered_map<int, int> &m) {

        if (preStart >= preEnd || inStart >= inEnd) {
            return nullptr;
        }

        auto root = new TreeNode(preorder[preStart]);
        auto inRoot = m.at(root->val);
        auto leftLen = inRoot - inStart;

        root->left = helper(preorder, inorder,
                            preStart + 1, preStart + 1 + leftLen,
                            inStart, inRoot,
                            m);
        root->right = helper(preorder, inorder,
                             preStart + 1 + leftLen, preEnd,
                             inRoot + 1, inEnd,
                             m);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;

        int i = 0;
        for (const auto &item : inorder) {
            m[item] = i;
            i++;
        }

        return helper(preorder, inorder,
                      0, preorder.size(),
                      0, inorder.size(),
                      m);
    }
};
