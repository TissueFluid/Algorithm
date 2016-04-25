// Spiral Matrix

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }

        if (matrix[0].empty()) {
            return {};
        }

        const int N_ROWS = matrix.size();
        const int N_COLS = matrix[0].size();

        vector<int> result;

        int count = 0;
        int leftBound = 0;
        int rightBound = N_COLS - 1;
        int upBound = 0;
        int downBound = N_ROWS - 1;

        const int N = N_ROWS * N_COLS;
        while (count < N) {
            for (int i = leftBound; i <= rightBound && count < N; ++i) {
                result.push_back(matrix[upBound][i]);
                count++;
            }
            upBound++;

            for (int i = upBound; i <= downBound && count < N; ++i) {
                result.push_back(matrix[i][rightBound]);
                count++;
            }
            rightBound--;

            for (int i = rightBound; i >= leftBound && count < N; --i) {
                result.push_back(matrix[downBound][i]);
                count++;
            }
            downBound--;

            for (int i = downBound; i >= upBound && count < N; --i) {
                result.push_back(matrix[i][leftBound]);
                count++;
            }
            leftBound++;
        }

        return result;
    }
};
