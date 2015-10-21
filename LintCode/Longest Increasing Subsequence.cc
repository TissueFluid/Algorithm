// Longest Increasing Subsequence - DP

//

#include <iostream>
#include <vector>
using namespace std;

// int longestIncreasingSubsequence(vector<int> nums) {
//     const auto size = nums.size();

//     if (size == 0) {
//         return 0;
//     }

//     vector<int> dp(size, 1);
//     int result = 0;

//     for (size_t i = 0; i < size; ++i) {
//         for (size_t j = 0; j < i; ++j) {
//             if (nums[j] <= nums[i]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//         result = max(result, dp[i]);
//     }

//     return result;
// }

int binarySearch(const vector<int> &dp, int val) {
    const int size = dp.size();

    if (val < dp[0]) {
        return 0;
    }

    int left = 0;
    int right = size - 1;
    int mid = (left + right) >> 1;

    while (left < mid) {
        if (val < dp[mid]) {
            right = mid;
        } else {
            left = mid;
        }
        mid = (left + right) >> 1;
    }

    return right;
}

int longestIncreasingSubsequence(vector<int> nums) {
    const auto size = nums.size();

    if (size == 0) {
        return 0;
    }

    vector<int> dp;

    dp.push_back(nums[0]);

    for (size_t i = 1; i < size; ++i) {
        if (nums[i] >= dp.back()) {
            dp.push_back(nums[i]);
        } else {
            dp[binarySearch(dp, nums[i])] = nums[i];
        }
    }

    return dp.size();
}

int main() {
    cout << longestIncreasingSubsequence(vector<int>({5,4,1,2,3})) << endl;
    cout << longestIncreasingSubsequence(vector<int>({4,2,4,5,3,7})) << endl;
    return 0;
}
