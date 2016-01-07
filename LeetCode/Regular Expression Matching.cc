#include <string>
#include <vector>

using namespace std;

// . * : dp[i][j] = dp[i-1][j] || dp[i][j-2]
// c * : dp[i][j] = dp[i-1][j] && s[i] == p[j-1] || dp[i][j-2]
// . : dp[i][j] = dp[i-1][j-1]
// else : dp[i][j] = dp[i-1][j-1] && s[i] == p[j]
class Solution {
public:
    bool isMatch(string s, string p) {
        const int size_s = s.length();
        const int size_p = p.length();

        vector<vector<bool> > dp(size_s + 1, vector<bool>(size_p + 1));

        dp[0][0] = true;

        for (int i = 1; i <= size_p; ++i) {
            if (i == 1) {
                dp[0][i] = false;
            } else {
                dp[0][i] = dp[0][i - 2] && p[i - 1] == '*';
            }
        }

        for (int i = 1; i <= size_s; ++i) {
            dp[i][0] = false;
        }

        for (int i = 1; i <= size_s; ++i) {
            for (int j = 1; j <= size_p; ++j) {
                switch (p[j - 1]) {
                case '*':
                    if (p[j - 2] == '.') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    } else {
                        dp[i][j] = (dp[i-1][j] && s[i-1] == p[j-2]) || dp[i][j-2];
                    }
                    break;
                case '.':
                    dp[i][j] = dp[i-1][j-1];
                    break;
                default:
                    dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
                    break;
                }
            }
        }

        return dp[size_s][size_p];
    }
};
