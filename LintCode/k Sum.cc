// k Sum - DP

// i in [1, sizeA]
// j in [1, k]
// k in [1, target]
// dp[i][j][k] : select j items in first i elements that sum to k
//
// dp[i][j][k] += (dp[i-1][j][k] + dp[i-1][j-1][k-A[i-1]])

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int _kSum(vector<int> &A, const int k, const int target) {
        const int size = A.size();

        if (k < 0 || size < k) {
            return 0;
        }

        int dp[size + 1][k + 1][target + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= size; ++i) {
            dp[i][0][0] = 1;
        }

        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= i && j <= k; ++j) {
                for (int k = 1; k <= target; ++k) {
                    dp[i][j][k] += dp[i-1][j][k];
                    if (k - A[i-1] >= 0) {
                        dp[i][j][k] += dp[i-1][j-1][k-A[i-1]];
                    }
                }
            }
        }

        return dp[size][k][target];
    }
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        return this->_kSum(A, k, target);
    }
};

int main() {
    Solution s;

    cout << s.kSum({1, 2, 3, 4}, 2, 5) << endl;

    return 0;
}
