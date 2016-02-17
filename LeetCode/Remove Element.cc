// Remove Element

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;

        for (const auto &num : nums) {
            if (num != val) {
                nums[cnt] = num;
                cnt++;
            }
        }

        nums.resize(cnt);

        return cnt;
    }
};
