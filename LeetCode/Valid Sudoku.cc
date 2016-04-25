// Valid Sudoku

#include <vector>
using namespace std;

class Solution {
private:
    bool check(vector<vector<char> > &board,
               int x1, int y1, int x2, int y2) {
        vector<bool> table(9, false);

        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                char ch = board[i][j];
                if (ch != '.') {
                    if (table[ch - '0'] == true) {
                        return false;
                    }
                    table[ch - '0'] = true;
                }
            }
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (!check(board, 0, i, 8, i)) {
                return false;
            }
            if (!check(board, i, 0, i, 8)) {
                return false;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!check(board, i, j, i + 2, j + 2)) {
                    return false;
                }
            }
        }

        return true;
    }
};
