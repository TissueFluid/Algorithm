// Search in Rotated Sorted Array II

#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            const int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]) {
                if (nums[mid] < target && target <= nums[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                while (left < right && nums[left] == nums[mid]) {
                    left++;
                }

                while (left < right && nums[mid] == nums[right - 1]) {
                    right--;
                }
            }
        }

        return false;
    }
};
