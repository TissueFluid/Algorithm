// Longest Increasing Continuous subsequence II

#include <iostream>
#include <vector>
using namespace std;

#define NOT_VISITED (-1)
class Solution {
private:
    int dfs(vector<vector<int> > &A, int i, int j, vector<vector<int> > &dp) {
        static const int width = A.size();
        static const int height = A[0].size();

        if (dp[i][j] != NOT_VISITED) {
            return dp[i][j];
        }

        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;

        if (i > 0 && A[i - 1][j] > A[i][j]) {
            up = dfs(A, i - 1, j, dp);
        }

        if (i < width - 1 && A[i + 1][j] > A[i][j]) {
            down = dfs(A, i + 1, j, dp);
        }

        if (j > 0 && A[i][j - 1] > A[i][j]) {
            left = dfs(A, i, j - 1, dp);
        }

        if (j < height - 1 && A[i][j + 1] > A[i][j]) {
            right = dfs(A, i, j + 1, dp);
        }

        dp[i][j] = 1 + max(max(up, down), max(left, right));

        return dp[i][j];
    }
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        const int height = A.size();

        if (height == 0) {
            return 0;
        }

        const int width = A[0].size();

        if (width == 0) {
            return 0;
        }

        vector<vector<int> > dp(height, vector<int>(width, NOT_VISITED));
        int result = 0;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                dfs(A, i, j, dp);
                result = max(result, dp[i][j]);
            }
        }

        return result;
    }
};
