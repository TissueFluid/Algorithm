// Copy Books

// dp[i][j] : time of j books copied by i workers
// dp[i][j] = min{max(dp[i-1][k from 0 to j-1], sum(pages[k+1 to j]))}

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        const int size = pages.size();

        if (k <= 0) {
            return -1;
        }

        if (size == 0) {
            return 0;
        }

        if (size <= k) {
            int maximum = pages[0];
            for (int i = 1; i < size; ++i) {
                maximum = max(maximum, pages[i]);
            }
            return maximum;
        }

        vector<int> sum_end_with(size, 0);

        sum_end_with[0] = pages[0];
        for (int i = 1; i < size; ++i) {
            sum_end_with[i] = sum_end_with[i - 1] + pages[i];
        }

        vector<vector<int> > dp(k + 1, vector<int>(size, numeric_limits<int>::max()));

        for (int i = 0; i < size; ++i) {
            dp[1][i] = sum_end_with[i];
        }

        for (int i = 2; i <= k; ++i) {
            dp[i][0] = pages[i];
            for (int j = 1; j < size; ++j) {
                for (int t = 0; t < j; ++t) {
                    int sum = sum_end_with[j] - sum_end_with[t];
                    dp[i][j] = min(dp[i][j], max(dp[i-1][t], sum));
                }
            }
        }

        return dp[k][size - 1];
    }
};
