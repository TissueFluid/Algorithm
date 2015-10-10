// Maximum Subarray - DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int> nums) {
    auto size = nums.size();

    if (size == 0) {
        return 0;
    }

    vector<int> sum(size, 0);

    sum[0] = nums[0];
    int result = sum[0];
    for (size_t i = 1; i < size; ++i) {
        sum[i] = max(nums[i], nums[i] + sum[i-1]);
        result = max(result, sum[i]);
    }

    return result;
}
