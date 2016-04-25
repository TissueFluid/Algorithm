// Permutations II

#include <vector>
using namespace std;

class Solution {
private:
    void helper(vector<int> &nums,
                vector<bool> &visited,
                vector<vector<int> > &result) {
        static vector<int> tmp;

        if (tmp.size() == nums.size()) {
            result.push_back(tmp);
            return;
        }

        const int N = nums.size();
        for (int i = 0; i < N; ++i) {
            if (visited[i] || (i > 0 && !visited[i-1] && nums[i] == nums[i-1])) {
                continue;
            }
            visited[i] = true;
            tmp.push_back(nums[i]);
            helper(nums, visited, result);
            tmp.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;

        if (nums.empty()) {
            return result;
        }

        vector<bool> visited(nums.size(), false);

        sort(nums.begin(), nums.end());
        helper(nums, visited, result);

        return result;
    }
};
