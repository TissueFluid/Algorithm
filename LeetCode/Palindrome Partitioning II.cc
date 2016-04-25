// Palindrome Partitioning II

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minCut(string s) {
    const int LEN = s.length();

    if (LEN == 0) {
      return 0;
    }

    bool isPal[LEN];
    int dp[LEN];

    for (int j = 0; j < LEN; ++j) {
      dp[j] = j;
      for (int i = 0; i <= j; ++i) {
        if (i + 1 < j) {
          isPal[i] = s[i] == s[j] && isPal[i+1];
        } else {
          isPal[i] = s[i] == s[j];
        }
        if (isPal[i]) {
          if (i > 0) {
            dp[j] = min(dp[j], 1 + dp[i-1]);
          } else {
            dp[j] = 0;
          }
        }
      }
    }

    return dp[LEN - 1];
  }
};
