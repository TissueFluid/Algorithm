#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (const auto &item : nums) {
            result ^= item;
        }

        return result;
    }
};
