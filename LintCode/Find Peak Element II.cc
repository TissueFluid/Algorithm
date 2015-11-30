// Find Peak Element II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    inline bool isValid(vector<vector<int> > &A, int x, int y) {
        static const int height = A.size();
        static const int width = A[0].size();

        if (x > 0 && y > 0 && x < height - 1 && y < width - 1) {
            return true;
        }
        return false;
    }
    inline bool isPeak(vector<vector<int> > &A, int x, int y) {
        return (
            A[x][y] > A[x+1][y] &&
            A[x][y] > A[x-1][y] &&
            A[x][y] > A[x][y-1] &&
            A[x][y] > A[x][y+1]);
    }
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        const int height = A.size();

        if (height < 3) {
            return {};
        }

        const int width = A[0].size();

        if (width < 3) {
            return {};
        }

        int x = 1;
        int y = 1;

        while (isValid(A, x, y)) {
            if (isPeak(A, x, y)) {
                return {x, y};
            }

            if (x + 1 < height - 1 && y + 1 < width - 1) {
                if (A[x+1][y] > A[x][y+1]) {
                    x++;
                } else {
                    y++;
                }
            } else {
                if (x + 1 < height - 1) {
                    x++;
                } else if (y + 1 < width - 1) {
                    y++;
                } else {
                    return {};
                }
            }
        }

        return {};
    }
};
