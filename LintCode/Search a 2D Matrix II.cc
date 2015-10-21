// Search a 2D Matrix II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        const int height = matrix.size();

        if (height == 0) {
            return 0;
        }

        const int width = matrix[0].size();

        if (width == 0) {
            return 0;
        }

        int occurrence = 0;

        int x = height - 1;
        int y = 0;

        while (x >= 0 && y < width) {
            if (matrix[x][y] > target) {
                x--;
            } else if (matrix[x][y] < target) {
                y++;
            } else {
                occurrence++;
                x--;
                y++;
            }
        }

        return occurrence;
    }
};
