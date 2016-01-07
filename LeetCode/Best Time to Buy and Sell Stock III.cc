#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int SIZE_PRICES = prices.size();

        if (SIZE_PRICES < 2) {
            return 0;
        }

        vector<int> maxFromZeroToI(SIZE_PRICES, 0);
        int currMinPrice = prices[0];

        for (int i = 1; i < SIZE_PRICES; ++i) {
            currMinPrice = min(currMinPrice, prices[i]);
            maxFromZeroToI[i] = max(prices[i] - currMinPrice, maxFromZeroToI[i-1]);
        }

        int currMaxPrice = prices[SIZE_PRICES - 1];
        int maxFromIToEnd = 0;
        int result = maxFromZeroToI[SIZE_PRICES - 1];

        for (int i = SIZE_PRICES - 2; i >= 0; --i) {
            currMaxPrice = max(currMaxPrice, prices[i]);
            maxFromIToEnd = max(maxFromIToEnd, currMaxPrice - prices[i]);
            result = max(result, maxFromIToEnd + maxFromZeroToI[i]);
        }

        return result;
    }
};
