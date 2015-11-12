// Number of Islands

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int count;
    void visit(vector<vector<bool> > &grid, vector<vector<bool> > &visited,
               int i, int j, bool isFirst) {
        static const int height = grid.size();
        static const int width = grid[0].size();

        if (i < 0 || j < 0 || i >= height || j >= width || visited[i][j]) {
            return;
        }
        visited[i][j] = true;

        if (grid[i][j] == false) {
            return;
        }

        if (isFirst) {
            count++;
        }

        visit(grid, visited, i + 1, j, false);
        visit(grid, visited, i - 1, j, false);
        visit(grid, visited, i, j + 1, false);
        visit(grid, visited, i, j - 1, false);
    }
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        const int height = grid.size();

        if (height == 0) {
            return 0;
        }

        const int width = grid[0].size();

        if (width == 0) {
            return 0;
        }

        vector<vector<bool> > visited(height, vector<bool>(width, false));
        count = 0;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                visit(grid, visited, i, j, true);
            }
        }

        return count;
    }
};


int main() {
    Solution s;
    vector<vector<bool> > v = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };

    cout << s.numIslands(v) << endl;
    return 0;
}
