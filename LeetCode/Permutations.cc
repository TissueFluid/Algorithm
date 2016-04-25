// Permutations

#include <vector>
using namespace std;

class Solution {
private:
    void helper(vector<int> &nums,
                int start,
                int end,
                vector<vector<int> > &result) {
        if (start == end) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < end; ++i) {
            swap(nums[i], nums[start]);
            helper(nums, start + 1, end, result);
            swap(nums[i], nums[start]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;

        if (nums.empty()) {
            return result;
        }

        helper(nums, 0, nums.size(), result);

        return result;
    }
};
