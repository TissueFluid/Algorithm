// Segment Tree Query II

#include <iostream>
#include <vector>
using namespace std;

class SegmentTreeNode {
public:
    int start, end, count;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int count) {
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if (root == NULL || start > end) {
            return 0;
        }

        if (start <= root->start && end >= root->end) {
            return root->count;
        }

        int mid = (root->start + root->end) / 2;

        if (start <= mid) {
            if (end <= mid) {
                return query(root->left, start, end);
            } else {
                return query(root->left, start, mid)
                    + query(root->right, mid + 1, end);
            }
        } else {
            return query(root->right, start, end);
        }
    }
};
