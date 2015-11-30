// Interval Minimum Number

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
    struct SegmentTree {
        int start;
        int end;
        int minimum;
        SegmentTree *left;
        SegmentTree *right;

        SegmentTree(int _start, int _end, int _minimum) {
            start = _start;
            end  = _end;
            minimum = _minimum;
            left = right = NULL;
        }
    };

    SegmentTree *build(vector<int> &A, int start, int end) {
        if (start > end) {
            return NULL;
        }

        if (start == end) {
            return new SegmentTree(start, end, A[start]);
        }

        int mid = (start + end) / 2;

        auto left = build(A, start, mid);
        auto right = build(A, mid + 1, end);

        auto new_node = new SegmentTree(start, end, min(left->minimum, right->minimum));
        new_node->left = left;
        new_node->right = right;

        return new_node;
    }

    int query(SegmentTree *root, int start, int end) {
        if (root == NULL || start > end) {
            return numeric_limits<int>::min();
        }

        if (start <= root->start && end >= root->end) {
            return root->minimum;
        }

        int mid = (root->start + root->end) / 2;

        if (start <= mid) {
            if (end <= mid) {
                return query(root->left, start, end);
            } else {
                return min(query(root->left, start, mid),
                           query(root->right, mid + 1, end));
            }
        } else {
            return query(root->right, start, end);
        }
    }
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        auto root = this->build(A, 0, A.size() - 1);

        vector<int> result;
        for (const auto &item : queries) {
            result.push_back(query(root, item.start, item.end));
        }

        return result;
    }
};
