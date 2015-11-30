// Surrounded Regions

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    void dfs(vector<vector<char> > &board,
             vector<vector<bool> > &visited,
             int x, int y) {
        const static int rows = board.size();
        const static int cols = board[0].size();

        if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y]) {
            return;
        }

        visited[x][y] = true;

        if (board[x][y] == 'O') {
            dfs(board, visited, x + 1, y);
            dfs(board, visited, x - 1, y);
            dfs(board, visited, x, y + 1);
            dfs(board, visited, x, y - 1);
        }
    }
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        const int rows = board.size();

        if (rows == 0) {
            return;
        }

        const int cols = board[0].size();

        if (cols == 0) {
            return;
        }

        vector<vector<bool> > visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            dfs(board, visited, i, 0);
            dfs(board, visited, i, cols - 1);
        }

        for (int i = 1; i < cols - 1; ++i) {
            dfs(board, visited, 0, i);
            dfs(board, visited, rows - 1, i);
        }

        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
