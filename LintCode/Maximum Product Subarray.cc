// Maximum Product Subarray

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    auto size = nums.size();

    if (size == 0) {
        return 0;
    }

    vector<int> positive(size, 0);
    vector<int> negative(size, 0);

    if (nums[0] > 0) {
        positive[0] = nums[0];
    } else if (nums[0] < 0) {
        negative[0] = nums[0];
    }

    for (size_t i = 1; i < size; ++i) {
        if (nums[i] > 0) {
            positive[i] = max(nums[i], nums[i] * positive[i-1]);
            negative[i] = nums[i] * negative[i-1];
        } else if (nums[i] < 0) {
            positive[i] = nums[i] * negative[i-1];
            negative[i] = min(nums[i], nums[i] * positive[i-1]);
        }
    }

    int ret;

    if (positive[0] == 0 && negative[0] != 0) {
        ret = negative[0];
    } else {
        ret = positive[0];
    }
    for (size_t i = 1; i < size; ++i) {
        if (positive[i] == 0 && negative[i] != 0) {
            ret = max(negative[i], ret);
        } else {
            ret = max(positive[i], ret);
        }
    }

    return ret;
}

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums) << endl;
    return 0;
}
