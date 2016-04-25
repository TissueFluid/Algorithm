// Surrounded Regions - BFS

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    const int height = board.size();
    if (height == 0) {
      return;
    }

    const int width = board[0].size();
    if (width == 0) {
      return;
    }

    queue<pair<int, int> > q;

    auto process = [&](const int &x, const int &y) {
      if (board[x][y] == 'O') {
        board[x][y] = '.';
        q.push(make_pair(x, y));
      }
    };

    auto canBeSearched = [&](const int &x, const int &y) ->bool {
      if (x < 0 || y < 0 || x >= height || y >= width) {
        return false;
      } else {
        return true;
      }
    };

    for (int i = 0; i < height; ++i) {
      process(i, 0);
      process(i, width - 1);
    }

    for (int i = 1; i < width - 1; ++i) {
      process(0, i);
      process(height - 1, i);
    }

    while (!q.empty()) {
      const int qsize = q.size();

      for (int i = 0; i < qsize; ++i) {
        auto front = q.front();
        q.pop();

        vector<pair<int, int> > surrounding = {
          {front.first + 1, front.second},
          {front.first - 1, front.second},
          {front.first, front.second + 1},
          {front.first, front.second - 1}
        };

        for (const auto &item : surrounding) {
          if (canBeSearched(item.first, item.second)) {
            process(item.first, item.second);
          }
        }
      }
    }

    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        switch (board[i][j]) {
        case '.':
          board[i][j] = 'O';
          break;
        case 'O':
          board[i][j] = 'X';
          break;
        }
      }
    }
  }
};

/* stack overflow
class Solution {
protected:
  int width;
  int height;
  void dfs(int x, int y,
           vector<vector<char> > &board) {
    if (x < 0 || y < 0 || x >= height || y >= width) {
      return;
    }

    if (board[x][y] == 'O') {
      board[x][y] = '.';
      dfs(x + 1, y, board);
      dfs(x - 1, y, board);
      dfs(x, y + 1, board);
      dfs(x, y - 1, board);
    }
  }
public:
  void solve(vector<vector<char> > &board) {
    height = board.size();
    if (height == 0) {
      return;
    }
    width = board[0].size();
    if (width == 0) {
      return;
    }

    for (int i = 0; i < width; ++i) {
      dfs(0, i, board);
      dfs(height - 1, i, board);
    }

    for (int i = 1; i < height - 1; ++i) {
      dfs(i, 0, board);
      dfs(i, width - 1, board);
    }

    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        switch (board[i][j]) {
        case 'O':
          board[i][j] = 'X';
          break;
        case '.':
          board[i][j] = 'O';
          break;
        }
      }
    }
  }
};
*/
