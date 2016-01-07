#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() < 2) {
            return {};
        }

        int a_xor_b = 0;

        for (const auto &item : nums) {
            a_xor_b ^= item;
        }

        int lowest_one = a_xor_b & (-a_xor_b);
        int a = 0;

        for (const auto &item : nums) {
            if (item & lowest_one) {
                a ^= item;
            }
        }

        return {a, a ^ a_xor_b};
    }
};
