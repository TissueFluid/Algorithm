// Minimum Size Subarray Sum

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        const int size = nums.size();

        if (size == 0) {
            return -1;
        }

        int left = 0;
        int sum = 0;
        int result = numeric_limits<int>::max();

        for (int i = 0; i < size; ++i) {
            sum += nums[i];

            while (sum >= s) {
                result = min(result, i - left + 1);
                sum -= nums[left++];
            }
        }

        if (result == numeric_limits<int>::max()) {
            return -1;
        } else {
            return result;
        }
    }
};
