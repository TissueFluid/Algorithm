// N-Queens II

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void NQueens(int row, const int n, int &count) {
    static vector<int> cols;

    if (row == n) {
        count++;
        return;
    }

    for (int i = 0; i < n; ++i) {
        bool valid = true;
        for (int j = 0; j < row; ++j) {
            if (cols[j] == i || abs(cols[j] - i) == abs(row - j)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cols.push_back(i);
            NQueens(row + 1, n, count);
            cols.pop_back();
        }
    }

    return;
}

int totalNQueens(int n) {
    int result;

    NQueens(0, n, result);

    return result;
}

int main() {
    cout << totalNQueens(8) << endl;
    return 0;
}
