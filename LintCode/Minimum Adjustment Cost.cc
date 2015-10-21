// Minimum Adjustment Cost - DP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 100

int MinAdjustmentCost(vector<int> A, int target) {
    const auto sizeA = A.size();

    if (sizeA == 0) {
        return 0;
    }

    vector<vector<int> > dp(sizeA,
                            vector<int>(MAX + 1,
                                        numeric_limits<int>::max()));

    for (int i = 1; i <= MAX; ++i) {
        dp[0][i] = abs(i - A[0]);
    }

    for (size_t i = 1; i < sizeA; ++i) {
        for (int j = 1; j <= MAX; ++j) {
            int lower = max(1, j - target);
            int upper = min(MAX, j + target);

            for (int k = lower; k <= upper; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(j - A[i]));
            }
        }
    }

    int result = dp[sizeA - 1][1];

    for (int i = 2; i <= MAX; ++i) {
        result = min(result, dp[sizeA - 1][i]);
    }

    return result;
}

int main() {
    cout << MinAdjustmentCost(vector<int>({1, 4, 2, 3}), 1) << endl;
    return 0;
}
