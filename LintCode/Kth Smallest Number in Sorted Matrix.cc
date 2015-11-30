// Kth Smallest Number in Sorted Matrix

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
private:
    struct Point {
        int x;
        int y;
        int val;
        Point(int _x, int _y, int _val) : x(_x), y(_y), val(_val) {}
    };

    struct Compare {
        bool operator() (const Point &a, const Point &b) {
            return a.val > b.val;
        }
    };

    int horizontal_search(vector<vector<int> > &matrix, int k) {
        const int height = matrix.size();
        const int width = matrix[0].size();
        priority_queue<Point, vector<Point>, Compare> heap;

        for (int i = 0; i < min(k, height); ++i) {
            heap.push(Point(i, 0, matrix[i][0]));
        }

        for (int i = 0; i < k - 1; ++i) {
            auto top = heap.top();
            heap.pop();

            if (top.y + 1 < width) {
                heap.push(Point(top.x, top.y + 1, matrix[top.x][top.y + 1]));
            }
        }

        return heap.top().val;
    }

    int vertical_search(vector<vector<int> > &matrix, int k) {
        const int height = matrix.size();
        const int width = matrix[0].size();
        priority_queue<Point, vector<Point>, Compare> heap;

        for (int i = 0; i < min(k, width); ++i) {
            heap.push(Point(0, i, matrix[0][i]));
        }

        for (int i = 0; i < k - 1; ++i) {
            auto top = heap.top();
            heap.pop();

            if (top.x + 1 < height) {
                heap.push(Point(top.x + 1, top.y, matrix[top.x + 1][top.y]));
            }
        }

        return heap.top().val;
    }
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        const int height = matrix.size();
        const int width = matrix[0].size();

        if (k > width * height) {
            return -1;
        }

        int result;
        if (height < width) {
            result = horizontal_search(matrix, k);
        } else {
            result = vertical_search(matrix, k);
        }

        return result;
    }
};
