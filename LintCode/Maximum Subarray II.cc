// Maximum Subarray II - DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxTwoSubArrays(vector<int> nums) {
    const auto size = nums.size();

    int left_max[size];

    left_max[0] = nums[0];

    int previous_end_left_max = nums[0];
    int current_end_left_max = nums[0];

    for (size_t i = 1; i < size - 1; ++i) {
        current_end_left_max = max(previous_end_left_max + nums[i], nums[i]);
        left_max[i] = max(current_end_left_max, left_max[i - 1]);
        previous_end_left_max = current_end_left_max;
    }

    int previous_end_right_max = nums[size - 1];
    int current_end_right_max = nums[size - 1];
    int previous_right_max = nums[size - 1];
    int current_right_max = previous_right_max;

    int max_sum = current_right_max + left_max[size - 2];

    for (size_t i = size - 2; i > 0; i--) {
        current_end_right_max = max(previous_end_right_max + nums[i], nums[i]);
        previous_end_right_max = current_end_right_max;

        current_right_max = max(previous_right_max, current_end_right_max);
        previous_right_max = current_right_max;

        max_sum = max(max_sum, current_right_max + left_max[i-1]);
    }

    return max_sum;
}

int main() {
    cout << maxTwoSubArrays(vector<int>{1, 3, -1, 2, -1, 2}) << endl;
    return 0;
}
