// Word Search - Back tracking

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool DFS(vector<vector<char> > &board, const string &word, int start,
             vector<vector<bool> > &visited, int x, int y) {
        const int height = board.size();
        const int width = board[0].size();
        const int len = word.length();

        if (x < 0 || y < 0 || x >= height || y >= width || visited[x][y]) {
            return false;
        }

        bool ret = false;

        visited[x][y] = true;

        if (word[start] == board[x][y]) {
            if (start == len - 1) {
                ret = true;
            } else {
                ret = (DFS(board, word, start + 1, visited, x + 1, y)
                       || DFS(board, word, start + 1, visited, x, y + 1)
                       || DFS(board, word, start + 1, visited, x - 1, y)
                       || DFS(board, word, start + 1, visited, x, y - 1)
                    );
            }
        }

        visited[x][y] = false;

        return ret;
    }
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        const int height = board.size();

        if (height == 0) {
            return false;
        }

        const int width = board[0].size();

        if (width == 0) {
            return false;
        }

        vector<vector<bool> > visited(height, vector<bool>(width, false));

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (DFS(board, word, 0, visited, i, j) == true) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char> > board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    cout << s.exist(board, "ABCCED") << endl;
    cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;

    return 0;
}
