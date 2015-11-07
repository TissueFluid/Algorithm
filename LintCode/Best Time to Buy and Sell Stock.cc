// Best Time to Buy and Sell Stock

// for each prices[i]
//   ret = max(ret, prices[i] - min)

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

        int minimum = prices[0];
        int ret = 0;

        for (int i = 1; i < size; ++i) {
            minimum = min(minimum, prices[i]);
            ret = max(ret, prices[i] - minimum);
        }

        return ret;
    }
};
