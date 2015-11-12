// Submatrix Sum

// dp[i][j] : sum from (0, 0) to (i, j)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        vector<vector<int> > err = {
            {-1, -1},
            {-1, -1}
        };

        const int height = matrix.size();
        if (height == 0) {
            return err;
        }

        const int width = matrix[0].size();
        if (width == 0) {
            return err;
        }

        int dp[height][width];

        dp[0][0] = matrix[0][0];

        for (int i = 1; i < height; ++i) {
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }

        for (int i = 1; i < width; ++i) {
            dp[0][i] = dp[0][i-1] + matrix[0][i];
        }

        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                dp[i][j] = matrix[i][j]
                    + dp[i-1][j]
                    + dp[i][j-1]
                    - dp[i-1][j-1];
            }
        }

        for (int i = 0; i < height; ++i) {
            for (int j = i; j < height; ++j) {
                unordered_map<int, int> m;
                m[0] = -1;

                for (int k = 0; k < width; ++k) {
                    int sum;
                    if (i == 0) {
                        sum = dp[j][k];
                    } else {
                        sum = dp[j][k] - dp[i-1][k];
                    }

                    if (m.find(sum) == m.end()) {
                        m[sum] = k;
                    } else {
                        return {
                            {i, m[sum] + 1},
                            {j, k}
                        };
                    }
                }
            }
        }

        return err;
    }
};

int main() {
    Solution s;

    vector<vector<int> > matrix = {
        {1, 5, 7},
        {3, 7, -8},
        {4, -8, 9}
    };

    auto res = s.submatrixSum(matrix);
    cout << "(" << res[0][0] << ", " << res[0][1] << ")" << endl;
    cout << "(" << res[1][0] << ", " << res[1][1] << ")" << endl;


    return 0;
}
