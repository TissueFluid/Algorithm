// The Skyline Problem

#include <vector>
using namespace std;

class SegmentTreeNode {
protected:
    int start;
    int end;
    int height;
    SegmentTreeNode *left;
    SegmentTreeNode *right;

public:
    SegmentTreeNode(int _start, int _end, int _height) {
        start = _start;
        end = _end;
        height = _height;
        left = right = NULL;
    }

    static SegmentTreeNode *build(int _start, int _end) {
        auto *root = new SegmentTreeNode(_start, _end, 0);

        if (_start == _end) {
            return root;
        }

        int mid = (_start + _end) / 2;

        root->left = build(_start, mid - 1);
        root->right = build(mid + 1, _end);

        return root;
    }
};

class SegmentTree {
protected:
    SegmentTreeNode *root;

public:
    SegmentTree(int start, int end) {
        root = SegmentTreeNode::build(start, end);
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    }
};
