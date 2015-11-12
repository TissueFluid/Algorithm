// Recover Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        const int size = nums.size();

        if (size == 0 || size == 1) {
            return;
        }

        auto prev = nums.begin();
        auto curr = prev + 1;

        for ( ; curr != nums.end(); curr++) {
            if (*curr < *prev) {
                break;
            }
            prev = curr;
        }

        if (curr == nums.end()) {
            return;
        }

        reverse(nums.begin(), curr);
        reverse(curr, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 1, 2, 3};

    s.recoverRotatedSortedArray(nums);

    for (auto item : nums) {
        cout << item << endl;
    }

    return 0;
}
