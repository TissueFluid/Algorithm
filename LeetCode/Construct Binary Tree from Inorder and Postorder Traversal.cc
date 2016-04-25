// Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode *helper(vector<int>::const_iterator inStart,
                     vector<int>::const_iterator inEnd,
                     vector<int>::const_iterator postStart,
                     vector<int>::const_iterator postEnd,
                     const unordered_map<int, vector<int>::const_iterator > &m) {
        if (inStart == inEnd || postStart == postEnd) {
            return nullptr;
        }

        auto root = new TreeNode(*(prev(postEnd, 1)));
        auto inRoot = m.at(root->val);
        auto leftLen = distance(inStart, inRoot);

        root->left = helper(inStart, inRoot,
                            postStart, next(postStart, leftLen),
                            m);
        root->right = helper(next(inRoot, 1), inEnd,
                             next(postStart, leftLen), prev(postEnd, 1),
                             m);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, vector<int>::const_iterator > m;
        for (auto it = inorder.begin(); it != inorder.end(); ++it) {
            m[*it] = it;
        }
        return helper(inorder.begin(), inorder.end(),
                      postorder.begin(), postorder.end(),
                      m);
    }
};
