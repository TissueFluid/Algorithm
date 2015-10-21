// Minimum Subarray - DP
//   dp[i] = min(dp[i-1] + nums[i], nums[i])

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArray(vector<int> nums) {
    int result = nums[0];
    int previous = result;

    for (size_t i = 1; i < nums.size(); ++i) {
        previous = min(previous + nums[i], nums[i]);
        if (previous < result) {
            result = previous;
        }
    }

    return result;
}

int main() {
    cout << minSubArray(vector<int>{1, -1, -2, 1}) << endl;
    return 0;
}
