// Jump Game

#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int fastest = 0;

        for (int i = 0; i <= min(fastest, N-1); i++) {
            fastest = max(fastest, i + nums[i]);
            if (fastest >= N - 1) {
                return true;
            }
        }

        return false;
    }
};
