// Rotate Image

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();

        for (int i = 0; i < N / 2; ++i) {
            for (int j = 0; j <= (N-1) / 2; ++j) {
                swap(matrix[i][j], matrix[j][N-i-1]);
                swap(matrix[i][j], matrix[N-i-1][N-j-1]);
                swap(matrix[i][j], matrix[N-j-1][i]);
            }
        }
    }
};
