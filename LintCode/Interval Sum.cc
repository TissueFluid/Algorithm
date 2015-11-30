// Interval Sum

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        const int size = A.size();
        vector<long long> dp(size, 0);

        dp[0] = A[0];
        for (int i = 1; i < size; ++i) {
            dp[i] = dp[i - 1] + A[i];
        }

        vector<long long> result;

        for (const auto & item : queries) {
            if (item.start == 0) {
                result.push_back(dp[item.end]);
            } else {
                result.push_back(dp[item.end] - dp[item.start - 1]);
            }
        }

        return result;
    }
};
