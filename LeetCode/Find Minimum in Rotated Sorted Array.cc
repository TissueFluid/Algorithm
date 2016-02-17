// Find Minimum in Rotated Sorted Array

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            const int mid = (left + right) / 2;

            if (nums[left] > nums[mid]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                return nums[left];
            }
        }

        return nums[left];
    }
};
