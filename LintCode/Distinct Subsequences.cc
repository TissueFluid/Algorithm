// Distinct Subsequences - DP
//   S : i
//   T : j
//   if S[i] == T[j]
//     dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
//   else
//     dp[i][j] = dp[i-1][j]

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int numDistinct(string &S, string &T) {
//     auto lenT = T.length();
//     auto lenS = S.length();

//     if (lenT == 0 || lenS == 0) {
//         return 0;
//     }

//     vector<vector<int> > dp(lenS+1, vector<int>(lenT+1, 0));

//     for (size_t i = 0; i <= lenS; ++i) {
//         dp[i][0] = 1;
//     }

//     for (size_t i = 1; i <= lenS; ++i) {
//         for (size_t j = 1; j <= lenT; ++j) {
//             dp[i][j] = dp[i-1][j];
//             if (S[i-1] == T[j-1]) {
//                 dp[i][j] += dp[i-1][j-1];
//             }
//         }
//     }

//     return dp[lenS][lenT];
// }

int numDistinct(string &S, string &T) {
    const auto lenT = T.length();
    const auto lenS = S.length();

    if (lenT == 0 || lenS == 0) {
        return 0;
    }

    int *p = new int[lenS + 1];
    int *q = new int[lenS + 1];

    memset(p, 0, sizeof(int) * (lenS + 1));
    memset(q, 0, sizeof(int) * (lenS + 1));

    p[0] = q[0] = 1;

    int *previous = p;
    int *current = q;

    for (size_t i = 1; i < lenS + 1; ++i) {
        for (size_t j = 1; j < lenT + 1; ++j) {
            current[j] = previous[j];
            if (S[i-1] == T[j-1]) {
                current[j] += previous[j-1];
            }
        }
        swap(previous, current);
    }

    int ret = previous[lenT];

    delete[] p;
    delete[] q;

    return ret;
}

int main() {
    string s1("rabbbit");
    string s2("rabbit");
    cout << numDistinct(s1, s2) << endl;
    return 0;
}
