// Valid Sudoku

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
    bool check(const vector<vector<char> > &board, int startx, int starty,
               int endx, int endy) {
        unordered_set<char> s;

        for (int i = startx; i <= endx; ++i) {
            for (int j = starty; j <= endy; ++j) {
                if (!isdigit(board[i][j]) || board[i][j] == '0') {
                    continue;
                }
                if (s.find(board[i][j]) == s.end()) {
                    s.insert(board[i][j]);
                } else {
                    return false;
                }
            }
        }

        return true;
    }
public:
    /**
     * @param board: the board
     * @return: wether the Sudoku is valid
     */
    bool isValidSudoku(const vector<vector<char>>& board) {
        const int height = board.size();

        if (height != 9) {
            return false;
        }

        const int width = board[0].size();

        if (width != 9) {
            return false;
        }

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
