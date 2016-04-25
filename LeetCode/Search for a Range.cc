// Search for a Range

#include <vector>
using namespace std;

class Solution {
private:
    int helper(vector<int> &nums,
               int target, int left, int right) {
        left--;
        right++;
        while (left + 1 < right) {
            const int mid = (left + right) / 2;

            if (target <= nums[mid]) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return right;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = helper(nums, target, 0, nums.size() - 1);

        if (nums[first] != target) {
            return {-1, -1};
        }

        int second = helper(nums, target + 1, first + 1, nums.size() - 1) - 1;

        return {first, second};
    }
};
