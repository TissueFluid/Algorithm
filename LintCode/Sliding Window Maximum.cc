// Sliding Window Maximum - deque


#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;

        const int size = nums.size();
        if (size == 0 || k <= 0) {
            return result;
        }

        deque<int> dq;

        for (int i = 0; i < size; ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (dq.front() + k == i) {
                dq.pop_front();
            }

            if (i + 1 >= k) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    vector<int> v({1,2,7,7,2});
    Solution s;

    auto result = s.maxSlidingWindow(v, 1);

    for (const auto &item : result) {
        cout << item << endl;
    }

    return 0;
}
