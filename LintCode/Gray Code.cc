// Gray Code

// 00
// 01
// 11
// 10

//  00
//  01
//  11
//  10
// 110
// 111
// 101
// 100

// 1 concatenated with grayCode[n - 1].reverse()

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 0) {
            return {};
        }

        vector<int> result({0});

        for (int i = 1; i <= n; ++i) {
            const int size = result.size();

            for (int j = size - 1; j >= 0; --j) {
                result.push_back(result[j] | (1 << (i-1)));
            }
        }

        return result;
    }
};
