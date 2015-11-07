// Median of two Sorted Arrays

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */

private:
    int findKth(const vector<int> &A, int endA,
                const vector<int> &B, int endB, int k) {
        if (endA == 0) {
            return B[endB - k];
        }

        if (endB == 0) {
            return A[endA - k];
        }

        if (k == 1) {
            return max(A[endA - 1], B[endB - 1]);
        }

        if (endA - k/2 < 0 || (endB - k/2 >= 0 && A[endA - k/2] < B[endB - k/2])) {
            return findKth(A, endA, B, endB - k/2, k - k/2);
        } else {
            return findKth(A, endA - k/2, B, endB, k - k/2);
        }
    }

public:
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        const int sizeA = A.size();
        const int sizeB = B.size();
        const int N = sizeA + sizeB;

        if (N % 2 == 1) {
            return (double)findKth(A, sizeA, B, sizeB, N / 2 + 1);
        } else {
            int left = findKth(A, sizeA, B, sizeB, N / 2);
            int right = findKth(A, sizeA, B, sizeB, N / 2 + 1);
            return (double)(left + right) / 2.0;
        }
    }
};

int main() {
    Solution s;

    cout << s.findMedianSortedArrays({1, 2, 3, 4, 5, 6}, {2, 3, 4, 5}) << endl;
    cout << s.findMedianSortedArrays({1, 2, 3}, {4, 5}) << endl;
    return 0;
}
