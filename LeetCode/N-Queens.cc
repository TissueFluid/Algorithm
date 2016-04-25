// N-Queens

#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
private:
    void addToResult(vector<int> &position,
                     vector<vector<string> > &result) {
        const int N = position.size();
        result.push_back(vector<string>());

        for (int i = 0; i < N; ++i) {
            string row;
            for (int j = 0; j < N; ++j) {
                if (position[i] == j) {
                    row.push_back('Q');
                } else {
                    row.push_back('.');
                }
            }
            result.back().push_back(row);
        }
    }

    bool valid(vector<int> &position,
               int newPosition) {
        const int size = position.size();

        for (int i = 0; i < size; ++i) {
            if (position[i] == newPosition
                || abs(position[i] - newPosition) == size - i) {
                return false;
            }
        }

        return true;
    }

    void helper(vector<int> &position,
                int n,
                vector<vector<string> > &result) {
        if (position.size() == n) {
            addToResult(position, result);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (valid(position, i)) {
                position.push_back(i);
                helper(position, n, result);
                position.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > result;
        vector<int> position;

        helper(position, n, result);

        return result;
    }
};
