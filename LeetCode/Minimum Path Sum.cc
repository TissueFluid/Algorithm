// Minimum Path Sum

// dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int height = grid.size();

        if (height == 0) {
            return 0;
        }

        const int width = grid[0].size();

        if (width == 0) {
            return 0;
        }

        vector<int> dp(width);

        partial_sum(grid[0].begin(), grid[0].end(), dp.begin());

        for (int i = 1; i < height; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < width; ++j) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }

        return dp[width-1];
    }
};
