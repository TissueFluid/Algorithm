#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    void dfs(vector<int> &A, int start, int k, const int target,
             vector<vector<int> > &result) {
        static vector<int> tmp;
        static int sum = 0;
        static const int size = A.size();

        if (k == 0) {
            if (sum == target) {
                result.push_back(tmp);
            }
            return;
        }

        for (int i = start; i <= size - k; ++i) {
            sum += A[i];
            tmp.push_back(A[i]);
            dfs(A, i + 1, k - 1, target, result);
            tmp.pop_back();
            sum -= A[i];
        }
    }
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        const int size = A.size();
        vector<vector<int> > result;

        if (size == 0) {
            return result;
        }

        dfs(A, 0, k, target, result);

        return result;
    }
};

int main() {
    Solution s;

    auto res = s.kSumII({1, 2, 3, 4}, 2, 5);

    for (auto &row : res) {
        for (auto &item : row) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;

}
