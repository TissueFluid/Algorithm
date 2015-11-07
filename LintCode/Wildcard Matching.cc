// Wildcard Matching - DP

// given s[i], p[j]
// dp[i][j] denotes whether s[0:i] matches p[0:i]
//
// if   p[j] == '*' : dp[i][j] = dp[i][j-1] || dp[i-1][j]
// elif p[j] == '?' : dp[i][j] = dp[i-1][j-1]
// else             : dp[i][j] = dp[i-1][j-1] && p[j] == s[i]

#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) {
            return false;
        }

        const auto len_s = strlen(s);
        const auto len_p = strlen(p);

        int dp[len_s + 1][len_p + 1];

        memset(dp, 0, sizeof(dp));

        dp[0][0] = true;

        for (size_t i = 0; i < len_p && p[i] == '*'; ++i) {
            dp[0][i+1] = true;
        }

        for (size_t i = 0; i < len_s; ++i) {
            for (size_t j = 0; j < len_p; ++j) {
                if (p[j] == '*') {
                    dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
                } else if (p[j] == '?') {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = dp[i][j] && p[j] == s[i];
                }
            }
        }

        return dp[len_s][len_p];
    }
};

int main() {
    Solution s;

    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa", "aa") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", "?*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;

    return 0;
}
