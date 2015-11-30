#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        const int size = A.size();

        if (size == 0) {
            return 0;
        }

        vector<int> sum(size + 1, 0);
        int cnt = 0;

        partial_sum(A.cbegin(), A.cend(), sum.begin() + 1);

        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int tmp = sum[j] - sum[i];
                if (tmp <= end && tmp >= start) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
