// Spiral Matrix II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) {
            return {};
        }

        vector<vector<int> > result(n, vector<int>(n));

        enum Direction {
            RIGHT = 0,
            DOWN = 1,
            LEFT = 2,
            UP = 3
        };

        int x = 0;
        int y = 0;

        Direction dr = RIGHT;

        int up = 0;
        int left = 0;
        int right = n - 1;
        int down = n -1;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 1; i <= n * n; ++i) {
            result[x][y] = i;

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
