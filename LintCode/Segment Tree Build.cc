// Segment Tree Build

#include <iostream>

using namespace std;

class SegmentTreeNode {
public:
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end) {
            return NULL;
        }

        auto root = new SegmentTreeNode(start, end);

        if (start == end) {
            return root;
        }

        auto mid = (root->start + root->end) / 2;

        root->left = build(root->start, mid);
        root->right = build(mid + 1, root->end);

        return root;
    }
};
