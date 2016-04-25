// Convert Sorted List to Binary Search Tree

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
protected:
    TreeNode *helper(const vector<int> &v, int start ,int end) {
        if (start > end) {
            return nullptr;
        }

        const int mid = (start + end) / 2;
        auto root = new TreeNode(v[mid]);

        root->left = helper(v, start, mid - 1);
        root->right = helper(v, mid + 1, end);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> tmp;

        while (head) {
            tmp.push_back(head->val);
            head = head->next;
        }

        return helper(tmp, 0, tmp.size() - 1);
    }
};
