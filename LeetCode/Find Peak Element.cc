// Find Peak Element

#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start + 1 < end) {
            const int mid = (start + end) / 2;

            if (nums[mid - 1] < nums[mid]) {
                if (nums[mid] < nums[mid + 1]) {
                    start = mid;
                } else {
                    return mid;
                }
            } else {
                end = mid;
            }
        }

        return (nums[start] < nums[end] ? end : start);
    }
};
