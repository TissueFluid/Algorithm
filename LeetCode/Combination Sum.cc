// Combination Sum

// 递归
// func f(start, end) {
//   for i in [start, end] {
//     f(i, end)
//   }
// }
// 剪枝

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    bool helper(vector<int> &candidates, const int target,
                const int start,
                const int end,
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
            tmp.push_back(candidates[i]);
            cut_branch = helper(candidates,
                                target - candidates[i],
                                i, end, result);
            tmp.pop_back();
        }

        return false;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;

        if (candidates.empty()) {
            return result;
        }

        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, candidates.size() - 1, result);

        return result;
    }
};
