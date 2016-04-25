// Next Permutation

#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        const int N = nums.size();

        int i;
        for (i = N - 1; i > 0 && nums[i] <= nums[i-1]; --i);

        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j;
        for (j = i + 1; j < N && nums[j] > nums[i-1]; ++j);

        swap(nums[i-1], nums[j-1]);
        reverse(nums.begin() + i, nums.end());

        return;
    }
};
