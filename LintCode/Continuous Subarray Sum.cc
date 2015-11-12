// Continuous Subarray Sum - DP

// dp[i] : max sum end with i
// dp[i] = max(dp[i-1] + A[i], A[i])


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
    vector<int> continuousSubarraySum(vector<int>& A) {
        const int size = A.size();

        if (size == 0) {
            return {-1, -1};
        }

        int global_biggest = A[0];
        int global_start = 0;
        int global_end = 0;

        int local_biggest = A[0];
        int local_start = 0;

        for (int i = 1; i < size; ++i) {
            if (local_biggest + A[i] > A[i]) {
                local_biggest = local_biggest + A[i];
            } else {
                local_biggest = A[i];
                local_start = i;
            }

            if (local_biggest > global_biggest) {
                global_biggest = local_biggest;
                global_start = local_start;
                global_end = i;
            }
        }

        return {global_start, global_end};
    }
};
