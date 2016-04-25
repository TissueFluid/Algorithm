// Combinations

#include <vector>
#include <numeric>
using namespace std;

// faster
class Solution {
    void helper(int start,
                const int &n, int k,
                vector<vector<int> > &result) {
        static vector<int> tmp;

        if (k == 0) {
            result.push_back(tmp);
            return;
        }

        for (int i = start; i <= n - k + 1; ++i) {
            tmp.push_back(i);
            helper(i + 1, n, k - 1, result);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n || n <= 0 || k <= 0) {
            return {};
        }

        vector<vector<int> > result;

        helper(1, n, k, result);

        return result;
    }
};

// slower
class Solution2 {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n || n <= 0 || k <= 0) {
            return {};
        }

        vector<vector<int> > result;
        vector<int> tmp;

        tmp.push_back(1);

        while (!tmp.empty()) {
            if (n - tmp.back() + (int)tmp.size() < k) {
                tmp.pop_back();
                if (!tmp.empty()) {
                    ++tmp.back();
                }
            } else {
                if ((int)tmp.size() == k) {
                    result.push_back(tmp);
                    ++tmp.back();
                } else {
                    tmp.push_back(tmp.back() + 1);
                }
            }
        }

        return result;
    }
};
