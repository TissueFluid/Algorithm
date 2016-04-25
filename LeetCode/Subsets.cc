// Subsets

#include <vector>
using namespace std;

class Solution {
    void helper(const vector<int> &nums, int start,
                vector<vector<int> > &result) {
        static vector<int> subset;

        result.push_back(subset);

        const int sizeOfNums = nums.size();
        for (int i = start; i < sizeOfNums; ++i) {
            subset.push_back(nums[i]);
            helper(nums, i + 1, result);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;

        sort(nums.begin(), nums.end());
        helper(nums, 0, result);
        return result;
    }
};
