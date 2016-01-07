#include <vector>
using namespace std;

// localMax[i][j] = max(global[i-1][j-1] + max(0, diff), localMax[i-1][j] + diff)
// globalMax[i][j] = max(localMax[i][j], globalMax[i-1][j])

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int SIZE_PRICES = prices.size();

        if (k < 0) {
            return -1;
        }

        if (k == 0 || SIZE_PRICES < 2) {
            return 0;
        }

        if (k >= SIZE_PRICES) {
            int result = 0;
            for (int i = 1; i < SIZE_PRICES; ++i) {
                int diff = prices[i] - prices[i - 1];
                if (diff > 0) {
                    result += diff;
                }
            }

            return result;
        }

        vector<int> localMax(k + 1, 0);
        vector<int> globalMax(k + 1, 0);

        for (int i = 1; i < SIZE_PRICES; ++i) {
            int diff = prices[i] - prices[i - 1];

            for (int j = k; j > 0; j--) {
                localMax[j] = max(globalMax[j-1] + max(0, diff), localMax[j] + diff);
                globalMax[j] = max(localMax[j], globalMax[j]);
            }

        }

        return globalMax[k];
    }
};
