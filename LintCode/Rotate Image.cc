// Rotate Image


// (i,j) (j,N-1-i) (N-1-i, N-1-j) (N-1-j,i)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        const int height = matrix.size();

        if (height == 0) {
            return;
        }

        const int width = matrix[0].size();

        if (width != height) {
            return;
        }

        for (int i = 0; i < width / 2; ++i) {
            for (int j = 0; j < (width + 1) / 2; ++j) {
                swap(matrix[i][j], matrix[j][width - 1 - i]);
                swap(matrix[i][j], matrix[width - 1 - i][width - 1 - j]);
                swap(matrix[i][j], matrix[width - 1 - j][i]);
            }
        }
    }
};
