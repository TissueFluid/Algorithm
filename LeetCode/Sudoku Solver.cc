// Sudoku Solver

#include <vector>
using namespace std;

class Solution {
private:
    bool valid(vector<vector<char> > &board, int row, int col, int value) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == value || board[i][col] == value) {
                return false;
            }
        }

        int x = row - row % 3;
        int y = col - col % 3;

        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if (board[i][j] == value) {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char> > &board, int row, int col) {
        if (row == 9) {
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol >= 9) {
            nextCol = 0;
            nextRow++;
        }

        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        for (char i = '1'; i <= '9'; ++i) {
            if (valid(board, row, col, i)) {
                board[row][col] = i;
                if (helper(board, nextRow, nextCol) == true) {
                    return true;
                } else {
                    board[row][col] = '.';
                }
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
