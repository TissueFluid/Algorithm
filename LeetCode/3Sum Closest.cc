#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDist = numeric_limits<int>::max();
        int result = -1;
        const int size = nums.size();

        if (size < 3) {
            return -1;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 2; ) {
            int start = i + 1;
            int end = size - 1;

            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                int currDist = abs(sum - target);

                if (currDist < minDist) {
                    minDist = currDist;
                    result = sum;
                }

                if (sum <= target) {
                    do {
                        ++start;
                    } while (start < end && nums[start] == nums[start - 1]);
                }
                if (sum >= target) {
                    do {
                        --end;
                    } while (start < end && nums[end] == nums[end + 1]);
                }
            }
            do {
                ++i;
            } while (i < size - 2 && nums[i] == nums[i - 1]);
        }

        return result;
    }
};
