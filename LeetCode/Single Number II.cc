#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};

        for (auto item : nums) {
            for (int i = 31; i >= 0; --i) {
                count[i] += (item & 1);
                item >>= 1;
            }
        }

        int result = 0;

        for (int i = 0; i < 32; ++i) {
            result <<= 1;
            result += count[i] % 3;
        }

        return result;
    }
};
