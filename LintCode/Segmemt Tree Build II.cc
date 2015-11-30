// Segmemt Tree Build II

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
private:
    SegmentTreeNode * build(int start, int end, vector<int> &A) {
        if (start > end) {
            return NULL;
        }

        SegmentTreeNode * root = new SegmentTreeNode(start, end, 0);

        if (start == end) {
            root->left = root->right = NULL;
            root->max = A[start];
        } else {
            auto mid = (start + end) / 2;
            root->left = build(start, mid, A);
            root->right = build(mid + 1, end, A);
            root->max = max(root->left->max, root->right->max);
        }

        return root;
    }
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        const int size = A.size();

        return build(0, size - 1, A);
    }
};
