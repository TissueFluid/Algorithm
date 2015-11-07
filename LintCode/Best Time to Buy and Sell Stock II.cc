// Best Time to Buy and Sell Stock II
//
// Find acsending sequence
// Example :  1 2 3 4 | 3 | 2 3 4 5 10 | 9 | 8 | 7 | 6

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

        int ret = 0;

        for (int i = 1; i < size; ++i) {
            if (prices[i] > prices[i-1]) {
                ret += (prices[i] - prices[i-1]);
            }
        }

        return ret;
    }
};
