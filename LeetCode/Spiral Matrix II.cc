// Spiral Matrix II

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));

        int leftBound = 0;
        int rightBound = n - 1;
        int upBound = 0;
        int downBound = n - 1;
        int count = 0;
        const int N = n * n;


        while (count < N) {
            for (int i = leftBound; i <= rightBound && count < N; ++i) {
                result[upBound][i] = ++count;

            }
            upBound++;

            for (int i = upBound; i <= downBound && count < N; ++i) {
                result[i][rightBound] = ++count;
            }
            rightBound--;

            for (int i = rightBound; i >= leftBound && count < N; --i) {
                result[downBound][i] = ++count;
            }
            downBound--;

            for (int i = downBound; i >= upBound && count < N; --i) {
                result[i][leftBound] = ++count;
            }
            leftBound++;
        }

        return result;
    }
};
