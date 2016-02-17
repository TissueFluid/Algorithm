// Missing Number

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();

        for (int i = 0; i < N; ) {
            if (nums[i] < N && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            } else {
                i++;
            }
        }

        int result;

        for (result = 0; result < N; ++result) {
            if (nums[result] != result) {
                break;
            }
        }

        return result;
    }
};

// math

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();

        return (1 + N) * N / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
