// Coins in a Line II - DP

// dp[i] : max value got from i to end
// value1 = value[i] + min(dp[i+2], dp[i+3])
// value2 = value[i] + value[i+1] + min(dp[i+3], dp[i+4])
// dp[i] = max(value1, value2)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:

public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        const int size = values.size();

        switch (size) {
        case 0:
            return false;
        case 1:
        case 2:
            return true;
        case 3:
            return values[0] + values[1] > values[2];
        case 4:
            return values[0] + values[1] > values[2] + values[3]
                || values[0] + values[3] > values[1] + values[2];
        }

        vector<int> dp(size);
        int sum = values[size - 1] + values[size - 2] + values[size - 3];

        dp[size-1] = values[size-1];
        dp[size-2] = values[size-2] + values[size-1];
        dp[size-3] = values[size-3] + values[size-2];
        dp[size-4] = values[size-4] + max(values[size-3], values[size-1]);

        for (int i = size - 4; i >= 0; i--) {
            sum += values[i];
            int value1 = values[i] + min(dp[i+2], dp[i+3]);
            int value2 = values[i] + values[i+1] + min(dp[i+3], dp[i+4]);
            dp[i] = max(value1, value2);
        }

        return dp[0] * 2 > sum;
    }
};

int main() {
    Solution s;
    vector<int> v1({1, 2, 2});
    vector<int> v2({1, 2, 4});
    vector<int> v3({100,200,400,300,400,800,500,600,1200});

    cout << s.firstWillWin(v1) << endl;
    cout << s.firstWillWin(v2) << endl;
    cout << s.firstWillWin(v3) << endl;

    return 0;
}
