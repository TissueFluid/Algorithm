#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();

        if (size < 2) {
            return 0;
        }

        int result = 0;

        for (int i = 1; i < size; ++i) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) {
                result += diff;
            }
        }

        return result;
    }
};
