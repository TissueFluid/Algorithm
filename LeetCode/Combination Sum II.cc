// Combination Sum II

// 递归：
// func f(start, end) {
//   for i in [start, end] {
//     去重：candidates[i] == candidates[i-1]
//     f(i + 1, end)
//   }
// }

// 剪枝

#include <vector>
using namespace std;

class Solution {
private:
    bool helper(vector<int> &candidates, const int target,
                const int start, const int end,
                vector<vector<int> > &result) {
        static vector<int> tmp;
        if (target == 0) {
            result.push_back(tmp);
            return true;
        } else if (target < 0) {
            return true;
        }

        bool cut_branch = false;
        for (int i = start; i <= end && !cut_branch; ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            cut_branch = helper(candidates, target - candidates[i],
                                i + 1, end, result);
            tmp.pop_back();
        }

        return false;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;

        if (candidates.empty()) {
            return result;
        }

        sort(candidates.begin(), candidates.end());

        helper(candidates, target, 0, candidates.size() - 1, result);

        return result;
    }
};
