// Set Matrix Zeroes

#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int height = matrix.size();

        if (height == 0) {
            return;
        }

        const int width = matrix[0].size();

        if (width == 0) {
            return;
        }

        bool firstRowAllZero = false;
        bool firstColAllZero = false;

        if (matrix[0][0] == 0) {
            firstRowAllZero = firstColAllZero = true;
        } else {
            for (int i = 1; i < height; ++i) {
                if (matrix[i][0] == 0) {
                    firstColAllZero = true;
                    break;
                }
            }
            for (int i = 1; i < width; ++i) {
                if (matrix[0][i] == 0) {
                    firstRowAllZero = true;
                    break;
                }
            }
        }

        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < height; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < width; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < width; ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < height; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }

        if (firstRowAllZero) {
            for (int i = 0; i < width; ++i) {
                matrix[0][i] = 0;
            }
        }

        if (firstColAllZero) {
            for (int i = 0; i < height; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
