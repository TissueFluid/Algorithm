// Maximal Square

// dp[i][j] : the longest side length from (0,0) to (i,j)
// dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        const int height = matrix.size();

        if (height == 0) {
            return 0;
        }

        const int width = matrix[0].size();

        if (width == 0) {
            return 0;
        }

        vector<vector<int> > dp(height, vector<int>(width, 0));
        int result = 0;

        for (int i = 0; i < height; ++i) {
            dp[i][0] = matrix[i][0];
            result = max(result, dp[i][0]);
        }
        for (int i = 1; i < width; ++i) {
            dp[0][i] = matrix[0][i];
            result = max(result, dp[0][i]);
        }

        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                } else {
                    dp[i][j] = 0;
                }
                result = max(result, dp[i][j]);
            }
        }

        return result * result;
    }
};
