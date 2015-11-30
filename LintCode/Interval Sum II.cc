// Interval Sum II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    struct SegmentTree {
        int start;
        int end;
        long long sum;
        SegmentTree *left;
        SegmentTree *right;
        SegmentTree(int _start, int _end, int _sum) {
            start = _start;
            end = _end;
            sum = _sum;
            left = right = NULL;
        }
    };

    SegmentTree *build(const vector<int> &A, int start, int end) {
        if (start > end) {
            return NULL;
        }

        if (start == end) {
            return new SegmentTree(start, end, A[start]);
        }

        int mid = (start + end) / 2;
        auto left = build(A, start, mid);
        auto right = build(A, mid + 1, end);

        auto p = new SegmentTree(start, end, left->sum + right->sum);
        p->left = left;
        p->right = right;

        return p;
    }

    long long query(SegmentTree *p, int start, int end) {
        if (start <= p->start && end >= p->end) {
            return p->sum;
        }

        auto mid = (p->start + p->end) / 2;

        if (start <= mid) {
            if (end <= mid) {
                return query(p->left, start, end);
            } else {
                return query(p->left, start, mid)
                    + query(p->right, mid + 1, end);
            }
        } else {
            return query(p->right, start, end);
        }
    }

    void modify(SegmentTree *p, int index, int value) {
        if (!p || index < p->start || index > p->end) {
            return;
        }

        if (p->start == p->end) {
            p->sum = value;
        } else {
            modify(p->left, index, value);
            modify(p->right, index, value);
            p->sum = (p->left->sum + p->right->sum);
        }
    }

    SegmentTree *root;

public:
    /* you may need to use some attributes here */

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        root = build(A, 0, A.size() - 1);
    }

    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        if (root == NULL || start > end) {
            return -1;
        }

        return query(root, start, end);
    }

    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        modify(root, index, value);
    }
};
