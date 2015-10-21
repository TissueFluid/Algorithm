// Maximum Subarray III - DP

// i : i partitions
// j : first j elements
// dp[i][j] = max(d[i][j - 1],
//                 max{dp[i - 1][p] + maxsum(a[p+1]...a[j]) | p = i-1 ... j-1})

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int maxSubArray(vector<int> nums, int k) {
    const int size = nums.size();

    if (size < k) {
        return 0;
    }

    vector<vector<int> > dp(k + 1, vector<int>(size + 1, 0));

    for (int i = 1; i <= k; ++i) {
        int localMax = numeric_limits<int>::min();

        for (int j = i; j <= size; ++j) {
            localMax = max(localMax, dp[i-1][j-1] + nums[j-1]);
            if (j == i) {
                dp[i][j] = localMax;
            } else {
                dp[i][j] = max(localMax, dp[i][j-1]);
            }
        }
    }

    return dp[k][size];
}

int main() {
    cout << maxSubArray(vector<int>{-1,4,-2,3,-2,3}, 2) << endl;
    return 0;
}
