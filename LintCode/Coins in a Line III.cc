// Coins in a Line III

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    static inline int sum(int i, int j, const vector<int> &sum) {
        if (i == 0) {
            return sum[j];
        } else {
            return sum[j] - sum[i - 1];
        }
    }

public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        const int size = values.size();

        if (size == 0) {
            return false;
        }

        if (size % 2 == 0) { // even
            int sum_odd = 0;
            int sum_even = 0;

            for (int i = 0; i < size; i += 2) {
                sum_even += values[i];
                sum_odd += values[i + 1];
            }

            return sum_even != sum_odd;
        }

        vector<vector<int> > dp(size, vector<int>(size));
        vector<int> sum(size, 0);

        sum[0] = values[0];
        for (int i = 1; i < size; ++i) {
            sum[i] = sum[i - 1] + values[i];
        }

        for (int i = 0; i < size; ++i) {
            dp[i][i] = values[i];
        }

        for (int k = 1; k < size; ++k) {
            for (int i = 0; i + k < size; ++i) {
                int left = values[i] + this->sum(i+1, i+k, sum) - dp[i+1][i+k];
                int right= values[i+k] + this->sum(i, i+k-1, sum) - dp[i][i+k-1];
                dp[i][i+k] = max(left, right);
            }
        }

        return dp[0][size - 1] * 2 > this->sum(0, size - 1, sum);
    }
};
