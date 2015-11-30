// Post Office Problem

// cost[i][j] : the cost that build an office between i and j
// dp[i][j] : build j offices in first i villages

// dp[i][j] = min{dp[k][j - 1] + cost[k + 1][i] | k in [0, i)}

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
private:
    void computeCost(vector<int> &A, vector<vector<int> > &cost) {
        const int size = A.size();

        for (int i = 0; i < size; ++i) {
            cost[i][i] = 0;
            for (int j = i + 1; j < size; ++j) {
                int mid = (i + j) / 2;
                for (int k = i; k <= j; ++k) {
                    cost[i][j] += abs(A[k] - A[mid]);
                }
            }
        }
    }
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        const int size = A.size();

        if (size == 0 || k >= size) {
            return 0;
        }

        sort(A.begin(), A.end());

        vector<vector<int> > cost(size, vector<int>(size, 0));
        computeCost(A, cost);

        vector<vector<int> > dp(size, vector<int>(k, numeric_limits<int>::max()));

        for (int i = 0; i < k; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1; i < size; ++i) {
            dp[i][0] = cost[0][i];

            for (int j = 1; j < k; ++j) {
                for (int r = 0; r < i; ++r) {
                    dp[i][j] = min(dp[i][j],
                                   dp[r][j-1] + cost[r+1][i]);
                }
            }
        }

        return dp[size - 1][k - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> A({1, 2, 3, 4, 5});
    cout << s.postOffice(A, 2) << endl;
    return 0;
}
