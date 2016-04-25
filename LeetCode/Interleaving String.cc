// Interleaving String

/*
  dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1]
          or dp[i][j-1] && s2[j-1] == s3[i+j-1]
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int len1 = s1.length();
        const int len2 = s2.length();
        const int len3 = s3.length();

        if (len1 + len2 != len3) {
            return false;
        }

        if (s1 + s2 == s3) {
            return true;
        }

        vector<vector<bool> > dp(2, vector<bool>(len1 + 1));

        dp[0][0] = true;

        for (int i = 1; i <= len1; ++i) {
            dp[0][i] = (dp[0][i-1] && s1[i-1] == s3[i-1]);
        }

        int prev = 0;
        int curr = 1;

        for (int i = 1; i <= len2; ++i) {
            dp[curr][0] = (dp[prev][0] && s2[i-1] == s3[i-1]);

            for (int j = 1; j <= len1; ++j) {
                dp[curr][j] = \
                    (dp[prev][j] && s2[i-1] == s3[i+j-1])
                    || (dp[curr][j-1] && s1[j-1] == s3[i+j-1]);
            }

            swap(prev, curr);
        }

        return dp[prev][len1];
    }
};
