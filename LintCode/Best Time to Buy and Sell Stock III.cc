// Best Time to Buy and Sell Stock III - DP

// leftMax[i] : max profit from 0 to i
// result = max{leftMax[i] + rightMax}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        const int size = prices.size();

        if (size == 0) {
            return 0;
        }

        vector<int> leftMax(size);

        leftMax[0] = 0;
        int minimum = prices[0];

        for (int i = 1; i < size; ++i) {
            minimum = min(minimum, prices[i]);
            leftMax[i] = max(leftMax[i-1], prices[i] - minimum);
        }

        int maximum = prices[size - 1];
        int result = leftMax[size - 1];
        int rightMax = 0;
        for (int i = size - 2; i >= 0; i--) {
            maximum = max(maximum, prices[i]);
            rightMax = max(rightMax, maximum - prices[i]);
            result = max(result, leftMax[i] + rightMax);
        }

        return result;
    }
};
