// Wildcard Matching

// for each s[i] and p[j]
// dp[i][j] = dp[i][j-1] || dp[i-1][j]    if p[j] == '*'
//            dp[i-1][j-1]                if p[j] == '?'
//            dp[i-1][j-1] && s[i] == p[j]

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const int LEN_S = s.length();
        const int LEN_P = p.length();

        int si = 0;
        int pi = 0;
        int saved_si = -1;
        int saved_pi = -1;

        for ( ; si < LEN_S; ) {
            if (pi < LEN_P && (p[pi] == '?' || p[pi] == s[si])) {
                pi++;
                si++;
            } else if (pi < LEN_P && p[pi] == '*') {
                saved_pi = pi;
                saved_si = si;
                pi++;
            } else if (saved_pi != -1) {
                pi = saved_pi;
                saved_si++;
                si = saved_si;
            } else {
                return false;
            }
        }

        for ( ; pi < LEN_P; ++pi) {
            if (p[pi] != '*') {
                return false;
            }
        }

        return true;
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        const int LEN_S = s.length();
        const int LEN_P = p.length();

        vector<vector<bool> > dp(LEN_S + 1, vector<bool>(LEN_P + 1, false));

        dp[0][0] = true;
        for (int i = 1; i < LEN_P + 1; ++i) {
            if (dp[0][i - 1]) {
                dp[0][i] = (p[i - 1] == '*');
            } else {
                break;
            }
        }

        for (int i = 1; i < LEN_S + 1; ++i) {
            for (int j = 1; j < LEN_P + 1; ++j) {
                switch (p[j - 1]) {
                case '*':
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    break;
                case '?':
                    dp[i][j] = dp[i-1][j-1];
                    break;
                default:
                    dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
                    break;
                }
            }
        }

        return dp[LEN_S][LEN_P];
    }
};
