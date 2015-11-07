// Sliding Window Median - heap

#include <iostream>
#include <vector>
#include <queue>
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

        priority_queue<int> pq;

        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }

        result.push_back((&pq.top())[k / 2]);

        for (int i = k; i < size; ++i) {
        }

        return result;
    }
};
