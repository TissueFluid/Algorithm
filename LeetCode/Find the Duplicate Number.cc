// Find the Duplicate Number

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size();

        while (start < end) {
            if (nums[start] == start) {
                start++;
            } else {
                if (nums[nums[start]] == nums[start]) {
                    return nums[start];
                } else {
                    swap(nums[start], nums[nums[start]]);
                }
            }
        }

        return -1;
    }

};
