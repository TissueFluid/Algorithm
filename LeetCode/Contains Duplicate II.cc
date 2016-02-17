// Contains Duplicate II

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int N = nums.size();
        unordered_set<int> s;

        for (int i = 0; i < N; ++i) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }

            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};
