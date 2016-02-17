// Construct Binary Tree from Preorder and Inorder Traversal

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *helper(vector<int> &preorder,
                     int preorder_start,
                     int preorder_end,
                     vector<int> &inorder,
                     int inorder_start,
                     int inorder_end) {
        if (preorder_start > preorder_end) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preorder_start]);

        int inorder_root_pos = inorder_start;

        while (inorder_root_pos <= inorder_end) {
            if (inorder[inorder_root_pos] == preorder[preorder_start]) {
                break;
            }
            inorder_root_pos++;
        }

        int size_left_subtree = inorder_root_pos - inorder_start;

        root->left = helper(preorder,
                            preorder_start + 1,
                            preorder_start + size_left_subtree,
                            inorder,
                            inorder_start,
                            inorder_root_pos - 1);

        root->right = helper(preorder,
                             preorder_start + size_left_subtree + 1,
                             preorder_end,
                             inorder,
                             inorder_root_pos + 1,
                             inorder_end);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1);
    }
};
