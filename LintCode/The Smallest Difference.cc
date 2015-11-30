// The Smallest Difference

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        const int sizeA = A.size();
        const int sizeB = B.size();

        int ia;
        int ib;
        int result = numeric_limits<int>::max();

        for (ia = ib = 0; ia < sizeA ; ++ia) {
            while (ib < sizeB && B[ib] <= A[ia]) {
                ib++;
            }
            if (ib - 1 >= 0) {
                result = min(result, A[ia] - B[ib - 1]);
            }
            if (ib < sizeB) {
                result = min(result, B[ib] - A[ia]);
            }
        }

        return result;
    }
};
