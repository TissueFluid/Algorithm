// Word Search

#include <vector>
#include <string>
using namespace std;

class Solution {
    bool search(vector<vector<char> > &board,
                const string &word,
                int start,
                int x, int y) {
        if (start == word.length()) {
            return true;
        }

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }

        if (board[x][y] == word[start]) {
            board[x][y] = '\0';
            auto ret = search(board, word, start + 1, x - 1, y)
                || search(board, word, start + 1, x + 1, y)
                || search(board, word, start + 1, x, y - 1)
                || search(board, word, start + 1, x, y + 1);
            board[x][y] = word[start];
            return ret;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return false;
        }

        const int height = board.size();

        if (height == 0) {
            return false;
        }

        const int width = board[0].size();

        if (width == 0) {
            return false;
        }

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (search(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
