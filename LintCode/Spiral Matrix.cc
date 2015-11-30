// Spiral Matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int height = matrix.size();
        if (height == 0) {
            return {};
        }
        const int width = matrix[0].size();
        if (width == 0) {
            return {};
        }

        enum Direction {
            RIGHT = 0,
            DOWN = 1,
            LEFT = 2,
            UP = 3
        };

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int up = 0;
        int left = 0;
        int right = width - 1;
        int down = height - 1;

        int x = 0;
        int y = 0;

        vector<int> result;
        const int count = width * height;

        Direction dr = RIGHT;

        for (int i = 0; i < count; ++i) {
            result.push_back(matrix[x][y]);
            switch (dr) {
            case RIGHT:
                if (y == right) {
                    dr = DOWN;
                    up++;
                }
                break;
            case DOWN:
                if (x == down) {
                    dr = LEFT;
                    right--;
                }
                break;
            case LEFT:
                if (y == left) {
                    dr = UP;
                    down--;
                }
                break;
            case UP:
                if (x == up) {
                    dr = RIGHT;
                    left++;
                }
                break;
            }

            x += dx[dr];
            y += dy[dr];
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int> > matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    auto res = s.spiralOrder(matrix);

    for (const auto & item : res) {
        cout << item << endl;
    }

    return 0;
}
