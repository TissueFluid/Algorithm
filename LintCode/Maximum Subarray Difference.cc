// Maximum Subarray Difference - DP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxDiffSubArrays(vector<int> nums) {
    const auto size = nums.size();

    if (size < 2) {
        return -1;
    }

    int left_max[size];
    int left_min[size];

    left_max[0] = left_min[0] = nums[0];

    int previous_end_left_max = nums[0];
    int current_end_left_max = nums[0];
    int previous_end_left_min = nums[0];
    int current_end_left_min = nums[0];

    for (size_t i = 1; i < size - 1; ++i) {
        current_end_left_max = max(previous_end_left_max + nums[i], nums[i]);
        previous_end_left_max = current_end_left_max;

        current_end_left_min = min(previous_end_left_min + nums[i], nums[i]);
        previous_end_left_min = current_end_left_min;

        left_max[i] = max(left_max[i - 1], current_end_left_max);
        left_min[i] = min(left_min[i - 1], current_end_left_min);
    }

    int right_max[size];
    int right_min[size];

    right_max[size - 1] = right_min[size - 1] = nums[size - 1];

    int previous_begin_right_max = nums[size - 1];
    int current_begin_right_max = nums[size - 1];
    int previous_begin_right_min = nums[size - 1];
    int current_begin_right_min = nums[size - 1];

    int max_diff = max(abs(right_max[size - 1] - left_min[size - 2]),
                       abs(left_max[size - 2] - right_min[size - 1]));

    for (size_t i = size - 2; i > 0; i--) {
        current_begin_right_max = max(previous_begin_right_max + nums[i], nums[i]);
        previous_begin_right_max = current_begin_right_max;

        current_begin_right_min = min(previous_begin_right_min + nums[i], nums[i]);
        previous_begin_right_min = current_begin_right_min;

        right_max[i] = max(right_max[i + 1], current_begin_right_max);
        right_min[i] = min(right_min[i + 1], current_begin_right_min);

        max_diff = max(max_diff, max(abs(right_max[i] - left_min[i - 1]),
                                     abs(right_min[i] - left_max[i - 1])));
    }

    return max_diff;
}

int main() {
    cout << maxDiffSubArrays(vector<int>{1, 2, -3, 1}) << endl;
    return 0;
}
