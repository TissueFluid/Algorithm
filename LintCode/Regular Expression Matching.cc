// Regular Expression Matching

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) {
            return false;
        }

        const int len_s = strlen(s);
        const int len_p = strlen(p);

        bool dp[len_s + 1][len_p + 1];

        dp[0][0] = true;
        dp[0][1] = false;

        for (int i = 2; i <= len_p; ++i) {
            dp[0][i] = p[i - 1] == '*' && dp[0][i - 2];
        }

        for (int i = 1; i <= len_s; ++i) {
            dp[i][0] = false;
        }

        for (int i =1; i <= len_s; ++i) {
            for (int j = 1; j <= len_p; ++j) {
                if (p[j - 1] == '*') {
                    if (p[j - 2] == '.') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    } else {
                        dp[i][j] = (dp[i - 1][j] && s[i - 1] == p[j - 2])
                            || dp[i][j - 2];
                    }
                } else if (p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                }
            }
        }

        return dp[len_s][len_p];
    }
};
