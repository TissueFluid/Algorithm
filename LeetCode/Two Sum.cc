// Two sum
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        const int size = nums.size();

        if (size < 2) {
            return {};
        }

        for (int i = 0; i < size; ++i) {
            auto found = m.find(target - nums[i]);

            if (found != m.cend()) {
                return {found->second + 1, i + 1};
            }

            m[nums[i]] = i;
        }

        return {};
    }
};
