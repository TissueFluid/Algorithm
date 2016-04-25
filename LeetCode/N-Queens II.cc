// N-Queens II

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
private:
    bool valid(vector<int> &position, int newPosition) {
        const int N = position.size();

        for (int i = 0; i < N; ++i) {
            if (position[i] == newPosition
                || abs(position[i] - newPosition) == N - i) {
                return false;
            }
        }

        return true;
    }

    int helper(vector<int> &position, int n) {
        if (position.size() == n) {
            return 1;
        }

        int retval = 0;

        for (int i = 0; i < n; ++i) {
            if (valid(position, i)) {
                position.push_back(i);
                retval += helper(position, n);
                position.pop_back();
            }
        }

        return retval;
    }

public:
    int totalNQueens(int n) {
        vector<int> position;

        return helper(position, n);
    }
};
