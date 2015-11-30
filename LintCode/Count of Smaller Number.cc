// Count of Smaller Number

#include <iostream>
#include <vector>
#include <limits>
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

        if (start == end) {
            return new SegmentTree(start, end);
        }

        int mid = (start + end) / 2;

        auto left = build(start, mid);
        auto right = build(mid + 1, end);
        auto root = new SegmentTree(start, end);
        root->left = left;
        root->right = right;

        return root;
    }

    int query(SegmentTree *root, int start, int end) {
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

    void modify(SegmentTree *root, int index) {
        if (!root || index < root->start || index > root->end) {
            return;
        }

        if (root->start != root->end) {
            modify(root->left, index);
            modify(root->right, index);
        }

        root->count++;
    }

public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        const int size = A.size();

        if (size == 0) {
            return vector<int>(queries.size(), 0);
        }

        auto root = build(0, 10001);

        for (const auto &item : A) {
            modify(root, item);
        }

        vector<int> result;

        for (const auto &item : queries) {
            result.push_back(query(root, 0, item - 1));
        }

        return result;
    }
};
