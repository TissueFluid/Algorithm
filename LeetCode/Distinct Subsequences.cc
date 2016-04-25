// Distinct Subsequences

/*
 * dp[i][j] = dp[i-1][j] if s[i] == t[j]
 * do[i][j] = dp[i-1][j] + dp[i-1][j-1] if s[i] != t[j]
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        const int lenS = s.length();
        const int lenT = t.length();

        if (lenS == 0 || lenT == 0 || lenT > lenS) {
            return 0;
        }

        vector<int> dp(lenT, 0);

        for (int i = 0; i < lenS; ++i) {
            for (int j = lenT - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    if (j == 0) {
                        dp[j] += 1;
                    } else {
                        dp[j] += dp[j-1];
                    }
                }
            }
        }

        return dp[lenT - 1];
    }
};
