// Jump Game II

#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        int old_fastest = -1;
        int fastest = 0;
        int count = 0;

        while (fastest < N - 1) {
            int i = old_fastest + 1;

            old_fastest = fastest;
            int tmp = fastest;
            for (; i <= fastest; ++i) {
                tmp = max(tmp, i + nums[i]);
            }
            fastest = tmp;
            count++;
        }

        return count;
    }
};
