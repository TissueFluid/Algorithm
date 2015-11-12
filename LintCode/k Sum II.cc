// k Sum II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void addToResult(vector<int> &A, vector<int> &index,
                     vector<vector<int> > &result) {
        vector<int> tmp;
        for (auto item : index) {
            tmp.push_back(A[item]);
        }
        result.push_back(tmp);
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

        vector<int> one_solution;
        one_solution.push_back(0);
        int sum = 0;

        while (!one_solution.empty()) {
            int back = one_solution.back();
            int sol_size = one_solution.size();

            if (back >= size - k + sol_size) {
                one_solution.pop_back();
                sol_size--;
                if (sol_size > 0) {
                    sum -= A[one_solution.back()];
                    one_solution[sol_size - 1]++;
                }
            } else {
                sum += A[back];
                if (sol_size == k) {
                    if (sum == target) {
                        addToResult(A, one_solution, result);
                    }
                    sum -= A[back];
                    one_solution[sol_size - 1]++;
                } else {
                    one_solution.push_back(back + 1);
                }
            }
        }

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
