// Combination Sum III

// 无解条件 n > Sum(9-k ... 9) || n < Sum(1 ... k)
// 剪枝
// 递归: f(start, end) -> for i in [start, end]: do f(start + 1, end)

#include <vector>
using namespace std;

class Solution {
private:
    bool helper(int depth, vector<vector<int> > &result, int target,
                const int start, const int end) {
        static vector<int> tmp;

        if (depth == 0) {
            if (target == 0) {
                result.push_back(tmp);
                return true;
            } else if (target < 0) {
                return true;
            } else {
                return false;
            }
        }

        bool cut_branch = false;
        for (int i = start; i <= end && !cut_branch; ++i) {
            tmp.push_back(i);
            cut_branch = helper(depth - 1, result, target - i, i + 1, end);
            tmp.pop_back();
        }

        return false;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;

        if (k <= 0 || n <= 0 || n > (19 - k) * k / 2 || n < (1 + k) * k / 2) {
            return result;
        }

        helper(k, result, n, 1, 9);

        return result;
    }
};
