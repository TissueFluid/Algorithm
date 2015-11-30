// Sliding Window Median - heap

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        const int size = nums.size();

        if (size == 0 || k <= 0) {
            return result;
        }

        multiset<int, less<int>> min_set;
        multiset<int, greater<int>> max_set;

        for (int i = 0; i < size; ++i) {
            if (i >= k) {
                auto found = max_set.find(nums[i - k]);
                if (found != max_set.cend()) {
                    max_set.erase(found);
                } else {
                    min_set.erase(min_set.find(nums[i - k]));
                }
            }

            if (max_set.empty() || nums[i] > *max_set.cbegin()) {
                min_set.insert(nums[i]);
            } else {
                max_set.insert(nums[i]);
            }

            while (!min_set.empty() && min_set.size() > max_set.size()) {
                max_set.insert(*min_set.cbegin());
                min_set.erase(min_set.cbegin());
            }
            while (!max_set.empty() && max_set.size() > min_set.size() + 1) {
                min_set.insert(*max_set.cbegin());
                max_set.erase(max_set.cbegin());
            }

            if (i >= k - 1) {
                result.push_back(*max_set.cbegin());
            }
        }

        return result;
    }
};
