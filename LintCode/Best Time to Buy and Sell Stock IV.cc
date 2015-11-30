// Best Time to Buy and Sell Stock IV

// do j transactions on ith day
// local[i][j] : there's a transaction on ith day
// global[i][j]


// local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff)
// global[i][j] = max(global[i-1][j], local[i][j])

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        const int size = prices.size();

        if (k >= size) {
            int result = 0;
            for (int i = 1; i < size; ++i) {
                int diff = prices[i] - prices[i - 1];

                if (diff > 0) {
                    result += diff;
                }
            }

            return result;
        }

        vector<int> local(k + 1, 0);
        vector<int> global(k + 1, 0);

        for (int i = 1; i < size; ++i) {
            int diff = prices[i] - prices[i - 1];

            for (int j = k; j > 0; j--) {
                local[j] = max(global[j - 1] + max(diff, 0),
                               local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }

        return global[k];
    }
};
