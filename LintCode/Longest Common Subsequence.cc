// Longest Common Subsequence - DP

// if A[i] == B[j]; dp[i][j] = dp[i-1][j-1] + 1
//            else: dp[i][j] =

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int longestCommonSubsequence(string A, string B) {
    const auto lenA = A.length();
    const auto lenB = B.length();

    if (lenA == 0 || lenB == 0) {
        return 0;
    }

    vector<vector<int> > dp(lenA + 1, vector<int>(lenB + 1, 0));

    for (size_t i = 1; i <= lenA; ++i) {
        for (size_t j = 1; j <= lenB; ++j) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[lenA][lenB];
}

int main() {
    cout << longestCommonSubsequence(string("ABCD"), string("EDCA")) << endl;
    cout << longestCommonSubsequence(string("ABCD"), string("EACB")) << endl;
    return 0;
}
