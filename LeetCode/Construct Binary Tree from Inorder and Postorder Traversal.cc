// Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode *helper(vector<int> &inorder,
                     int inorder_start,
                     int inorder_end,
                     vector<int> &postorder,
                     int postorder_start,
                     int postorder_end) {
        if (inorder_start > inorder_end) {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[postorder_end]);

        int inorder_root_pos = inorder_start;

        while (inorder_root_pos <= inorder_end) {
            if (inorder[inorder_root_pos] == postorder[postorder_end]) {
                break;
            }
            inorder_root_pos++;
        }

        int size_left_subtree = inorder_root_pos - inorder_start;

        root->left = helper(inorder,
                            inorder_start,
                            inorder_root_pos - 1,
                            postorder,
                            postorder_start,
                            postorder_start + size_left_subtree - 1);

        root->right = helper(inorder,
                             inorder_root_pos + 1,
                             inorder_end,
                             postorder,
                             postorder_start + size_left_subtree,
                             postorder_end - 1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1,
                      postorder, 0, postorder.size() - 1);
    }
};
