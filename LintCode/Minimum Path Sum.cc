// Minimum Path Sum - DP

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        const size_t height = grid.size();

        if (height == 0) {
            return 0;
        }

        const size_t width = grid[0].size();

        if (width == 0) {
            return 0;
        }

        int dp[height][width];

        dp[0][0] = grid[0][0];

        for (size_t i = 1; i < height; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for (size_t i = 1; i < width; ++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for (size_t i = 1; i < height; ++i) {
            for (size_t j = 1; j < width; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[height-1][width-1];
    }
};

int main() {
    vector<vector<int> > v({
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
        });
    Solution s;
    cout << s.minPathSum(v) << endl;
    return 0;
}
