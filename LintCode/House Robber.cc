// House Robber

// dp[i] = max(dp[i - 2] + A[i], dp[i - 1])

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        const int size = A.size();

        if (size == 0) {
            return 0;
        }

        if (size ==  1) {
            return A[0];
        }

        if (size ==  2) {
            return max(A[0], A[1]);
        }

        long long dp_i;
        long long dp_i_2 = A[0];
        long long dp_i_1 = max(A[0], A[1]);

        for (int i = 2; i < size; ++i) {
            dp_i = max(dp_i_2 + A[i], dp_i_1);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i;
    }
};

int main() {
    Solution s;

    cout << s.houseRobber({3, 8, 4}) << endl;
    return 0;
}
