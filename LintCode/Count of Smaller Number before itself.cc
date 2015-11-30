// Count of Smaller Number before itself

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    struct SegmentTree {
        int start;
        int end;
        int count;
        SegmentTree *left;
        SegmentTree *right;

        SegmentTree(int _start, int _end) {
            start = _start;
            end = _end;
            count = 0;
            left = right = NULL;
        }
    };

    SegmentTree *build(int start, int end) {
        if (start > end) {
            return NULL;
        }

        auto root = new SegmentTree(start, end);

        if (start == end) {
            return root;
        }

        int mid = (start + end) / 2;
        root->left = build(start, mid);
        root->right = build(mid + 1, end);

        return root;
    }

    void modify(SegmentTree *root, int val) {
        if (root == NULL) {
            return;
        }

        if (root->start <= val && val <= root->end) {
            root->count++;
            modify(root->left, val);
            modify(root->right, val);
        }
    }

    int query(SegmentTree *root, int start, int end) {
        if (!root || start > end) {
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
public:
    /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        auto root = this->build(0, 10000);

        vector<int> result;

        for (const auto &item : A) {
            result.push_back(query(root, 0, item - 1));
            modify(root, item);
        }

        return result;
    }
};
