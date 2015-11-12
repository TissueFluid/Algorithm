// Matrix Zigzag Traversal

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> result;

        const int height = matrix.size();

        if (height == 0) {
            return result;
        }

        const int width = matrix[0].size();

        if (width == 0) {
            return result;
        }

        for (int i = 0; i < height + width; ++i) {
            if (i % 2 == 0) {
                int x = min(height - 1, i);
                int y = max(0, i - height + 1);
                while (x >= 0 && y < width) {
                    result.push_back(matrix[x][y]);
                    x--;
                    y++;
                }
            } else {
                int y = min(width - 1, i);
                int x = max(i - width + 1, 0);
                while (x < height && y >= 0) {
                    result.push_back(matrix[x][y]);
                    x++;
                    y--;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int> > matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    Solution s;

    auto res = s.printZMatrix(matrix);

    for (auto &item : res) {
        cout << item << endl;
    }
    return 0;
}
