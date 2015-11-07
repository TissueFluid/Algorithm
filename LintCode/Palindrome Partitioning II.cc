// Palindrome Partitioning II - DP

// isPal[i][j] denotes if s[i:j] is palindrome
// isPal[i][j] = (j - i >= 1 || isPal[i+1][j-1]) && s[i] == s[j]

// dp[j] denotes minCut from 0 to i
// i from 0 to j
// if isPal[i][j] : then dp[j] = min(dp[j], dp[i-1] + 1)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        const int size = s.length();

        if (size == 0) {
            return 0;
        }

        int dp[size];
        bool isPal[size][size];
        memset(dp, 0, sizeof(dp));
        memset(isPal, false, sizeof(isPal));
        // vector<int> dp(size);
        // vector<vector<bool> > isPal(size, vector<bool>(size));

        for (int j = 0; j < size; ++j) {
            dp[j] = j;
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j] && (j - i <= 1 || isPal[i+1][j-1])) {
                    isPal[i][j] = true;
                    if (i == 0) {
                        dp[j] = 0;
                    } else {
                        dp[j] = min(dp[j], 1 + dp[i-1]);
                    }
                }
            }
        }

        return dp[size - 1];
    }
};



int main() {
    Solution s;

    cout << s.minCut("aab") << endl;
    cout << s.minCut("ab") << endl;
    cout << s.minCut("a") << endl;
    cout << s.minCut("abc") << endl;
    cout << s.minCut("cabababcbc") << endl;

    return 0;
}
