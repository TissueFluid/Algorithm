// Maximum Subarray My Submissions Question

// for sum[0..i]:
//   result = max(result, sum[0..i] - minsum[0..i])
// Note: take care of the all negative case

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        bool allNegative = true;

        for (int i = 0; i < N; ++i) {
            if (nums[i] >= 0) {
                allNegative = false;
                break;
            }
        }

        if (allNegative) {
            return *max_element(nums.begin(), nums.end());
        }

        int result = 0;
        int minSum = 0;
        int sum = 0;

        for (int i = 0; i < N; ++i) {
            sum += nums[i];
            minSum = min(minSum, sum);
            result = max(result, sum - minSum);
        }

        return result;
    }
};
