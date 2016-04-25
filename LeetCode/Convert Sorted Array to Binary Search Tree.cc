// Convert Sorted Array to Binary Search Tree

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
protected:
    TreeNode *helper(const vector<int> &nums, const int start, const int end) {
        if (start > end) {
            return nullptr;
        }

        const int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
