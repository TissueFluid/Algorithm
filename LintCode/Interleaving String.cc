// Interleaving String - DP
//   if dp[i-1][j] is true && s1[i] == s3[i + j]; then
//     dp[i][j] = true
//   endif
//   if dp[i][j-1] is true && s2[j] == s3[i + j]; then
//     dp[i][j] = true
//   endif

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    const auto len1 = s1.length();
    const auto len2 = s2.length();
    const auto len3 = s3.length();

    if (len1 + len2 != len3) {
        return false;
    }

    vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));

    dp[0][0] = true;

    for (size_t i = 1; i < len1 + 1; ++i) {
        if (dp[i-1][0] && s1[i - 1] == s3[i - 1]) {
            dp[i][0] = true;
        }
    }

    for (size_t j = 1; j < len2 + 1; ++j) {
        if (dp[0][j-1] && s2[j - 1] == s3[j - 1]) {
            dp[0][j] = true;
        }
    }

    for (size_t i = 1; i < len1 + 1; ++i) {
        for (size_t j = 1; j < len2 + 1; ++j) {
            if ((dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]))
                || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]))) {
                dp[i][j] = true;
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    string s4("aadbbbaccc");

    cout << isInterleave(s1, s2, s3) << endl;
    cout << isInterleave(s1, s2, s4) << endl;

    return 0;
}
