// N-Queens

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void solveNQueensUsingRecursion(int row, int n,
                  vector<int> &cols, vector<vector<string> > &result) {
    if (row == n) {
        vector<string> solution;
        for (int i = 0; i < n; i++) {
            string s(n, '.');
            s[cols[i]] = 'Q';
            solution.push_back(s);
        }
        result.push_back(solution);
        return;
    }

    for (int i = 0; i < n; ++i) {
        bool valid = true;

        for (int j = 0; j < row; ++j) {
            if (cols[j] == i || abs(row - j) == abs(cols[j] - i)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cols[row] = i;
            solveNQueensUsingRecursion(row + 1, n, cols, result);
        }
    }

    return;
}

void solveNQueensUsingRecursion(int n, vector<vector<string> > &result) {
    vector<int> cols(n, -1);

    solveNQueensUsingRecursion(0, n, cols, result);

    return;
}

void solveNQueensUsingBacktrack(int n, vector<vector<string> > &result) {
    vector<int> cols(n, -1);
    int i, j, k;

    i = 0;
    j = 0;
    for (; i < n; ) {
        for (; j < n; ) {
            for (k = 0; k < i; k++) {
                if (cols[k] == j || abs(cols[k] - j) == abs(k - i)) {
                    break;
                }
            }

            if (k == i) { // valid position
                cols[i] = j;
                if (i == n - 1) {
                    vector<string> solution;
                    for (auto item : cols) {
                        string s(n, '.');
                        s[item] = 'Q';
                        solution.push_back(s);
                    }
                    result.push_back(solution);

                    j = cols[i] + 1;
                    cols[i] = -1;
                } else {
                    j = 0;
                    i++;
                }
            } else {
                j++;
            }
        }

        if (i == 0) {
            break;
        }
        cols[i] = -1;
        i--;
        j = cols[i] + 1;
    }

    return;
}

void solveNQueensUsingBitsets(int n, vector<vector<string> > &result) {

    return;
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;

    solveNQueensUsingRecursion(n, result);
    // solveNQueensUsingBacktrack(n, result);
    // solveNQueensUsingBitsets(n, result);

    return result;
}

int main() {
    auto result = solveNQueens(8);

    for (auto &i : result) {
        for (auto &j : i) {
            cout << j << endl;
        }
        cout << endl;
    }

    return 0;
}
