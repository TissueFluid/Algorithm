#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();

        if (size < 2) {
            return 0;
        }

        int currMinPrice = prices[0];
        int result = 0;

        for (int i = 1; i < size; ++i) {
            currMinPrice = min(currMinPrice, prices[i]);
            result = max(result, prices[i] - currMinPrice);
        }

        return result;
    }
};
