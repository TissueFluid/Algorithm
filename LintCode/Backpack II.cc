// Backpack II

// value[i][j] = max{max(value[i-1][j], value[i-1][j-A[i] + V[i]]}
// dp[j] = max{max(dp[j], dp[j-A[i]] + V[i])}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        const int size = A.size();

        if (size == 0 || m <= 0 || size != V.size()) {
            return 0;
        }

        vector<int> value(m + 1, 0);

        for (int i = 0; i < size; ++i) {
            for (int j = m; j >= A[i]; j--) {
                int currentMax = max(value[j], value[j-A[i]] + V[i]);
                value[j] = max(value[j], currentMax);
            }
        }

        return value[m];
    }
};

int main() {
    Solution s;

    cout << s.backPackII(10, {2, 3, 5, 7}, {1, 5, 2, 4}) << endl;

    return 0;
}
