// Candy

// 1 2 3 1
// 1 2 3 1

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        const int size = ratings.size();

        if (size == 0) {
            return 0;
        }

        vector<int> count(size, 1);

        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }

        int sum = 0;

        for (int i = size - 1; i > 0; --i) {
            sum += count[i];
            if (ratings[i - 1] > ratings[i] && count[i - 1] <= count[i]) {
                count[i - 1] = count[i] + 1;
            }
        }
        sum += count[0];

        return sum;
    }
};
