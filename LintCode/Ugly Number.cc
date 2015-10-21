// Ugly Number

#include <iostream>
#include <vector>

using namespace std;

long long kthPrimeNumber(int k) {
    if (k < 0) {
        return -1;
    }

    vector<long long> dp(k + 1, 0);

    dp[0] = 1;

    int i3, i5, i7;
    i3 = i5 = i7 = 0;

    for (int i = 1; i <= k; ++i) {
        dp[i] = min(dp[i3] * 3, min(dp[i5] * 5, dp[i7] * 7));

        while (dp[i3] * 3 <= dp[i]) {
            i3++;
        }
        while (dp[i5] * 5 <= dp[i]) {
            i5++;
        }
        while (dp[i7] * 7 <= dp[i]) {
            i7++;
        }
    }

    return dp[k];
}

int main() {
    for (int i = 1; i <= 12; ++i) {
        cout << kthPrimeNumber(i) << endl;
    }
    return 0;
}
