// Contains Duplicate III

// Time complexity: O(n*log(k))

#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
private:
    bool containsDuplicateII(vector<int> &nums, int k) {
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
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        const int N = nums.size();
        set<long long> s;

        if (t == 0) {
            return containsDuplicateII(nums, k);
        }

        for (int i = 0; i < N; ++i) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }

            auto upper = upper_bound(s.begin(), s.end(),
                                     (long long)nums[i] - t - 1);

            if (upper != s.end() && *upper <= (long long)nums[i] + t) {
                return true;
            } else {
                s.insert(nums[i]);
            }
        }

        return false;
    }
};
