// Unique Paths II

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    auto height = obstacleGrid.size();

    if (height == 0) {
        return 0;
    }

    auto width = obstacleGrid[0].size();

    if (width == 0) {
        return 0;
    }

    vector<vector<int> > result(height + 1, vector<int>(width + 1, 0));

    for (unsigned i = 0; i <= height; ++i) {
        result[i][0] = 0;
    }

    for (unsigned j = 0; j <= width; ++j) {
        result[0][j] = 0;
    }

    result[0][1] = 1;

    for (unsigned i = 1; i <= height; ++i) {
        for (unsigned j = 1; j <= width; ++j) {
            if (obstacleGrid[i-1][j-1] == 1) {
                result[i][j] = 0;
            } else {
                result[i][j] = result[i-1][j] + result[i][j-1];
            }
        }
    }

    return result[height][width];
}

int main() {
    vector<vector<int> > obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
}
