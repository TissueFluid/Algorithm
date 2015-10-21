// Edit Distance - DP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    auto len1 = word1.length();
    auto len2 = word2.length();

    if (word1 == word2) {
        return 0;
    }

    vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (size_t i = 0; i <= len1; ++i) {
        dp[i][0] = i;
    }
    for (size_t i = 1; i <= len2; ++i) {
        dp[0][i] = i;
    }

    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    cout << minDistance(string("mart"), string("karma")) << endl;
    cout << minDistance(string("sea"), string("ate")) << endl;
    return 0;
}
