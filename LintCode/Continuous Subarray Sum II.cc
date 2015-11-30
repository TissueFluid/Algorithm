// Continuous Subarray Sum II

// can rotate
// result = max(globalMax, sum - globalMin)

// Pay attention to the all negative case.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        const int size = A.size();

        if (size == 0) {
            return {-1, -1};
        }

        int sum = A[0];

        int globalMax = A[0];
        int globalMaxStart = 0;
        int globalMaxEnd = 0;

        int localMax = A[0];
        int localMaxStart = 0;

        int globalMin = A[0];
        int globalMinStart = 0;
        int globalMinEnd = 0;

        int localMin = A[0];
        int localMinStart = 0;

        for (int i = 1; i < size; ++i) {
            sum += A[i];
            if (localMax + A[i] > A[i]) {
                localMax += A[i];
            } else {
                localMax = A[i];
                localMaxStart = i;
            }

            if (localMax > globalMax) {
                globalMax = localMax;
                globalMaxStart = localMaxStart;
                globalMaxEnd = i;
            }

            if (localMin + A[i] < A[i]) {
                localMin += A[i];
            } else {
                localMin = A[i];
                localMinStart = i;
            }

            if (localMin < globalMin) {
                globalMin = localMin;
                globalMinStart = localMinStart;
                globalMinEnd = i;
            }
        }

        if (sum == globalMin || globalMax >= sum - globalMin) {
            return {globalMaxStart, globalMaxEnd};
        } else {
            return {globalMinEnd + 1, globalMinStart - 1};
        }
    }
};

int main() {
    Solution s;
    // vector<int> A = {1, -1};
    vector<int> A = {-101,-33,-44,-55,-67,-78,-101,-33,-44,-55,-67,-78,-100,-200,-1000,-22,-100,-200,-1000,-22};

    auto res = s.continuousSubarraySumII(A);

    cout << res[0] << " : " << res[1] << endl;
    return 0;
}
