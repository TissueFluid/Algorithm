// Subsets II

#include <vector>
using namespace std;

class Solution {
    void helper(vector<int> &nums, int start,
                vector<vector<int> > &result) {
        static vector<int> tmp;

        result.push_back(tmp);

        const int size = nums.size();
        if (start == size) {
            return;
        }

        for (int i = start; i < size; ++i) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            helper(nums, i + 1, result);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;

        helper(nums, 0, result);

        return result;
    }
};
