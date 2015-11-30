// Next Permutation II

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        const int size = nums.size();

        if (size <= 1) {
            return;
        }

        int i;
        for (i = size - 1; i >= 1 && nums[i-1] >= nums[i]; --i);

        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j;
        for (j = i; j < size && nums[j] > nums[i-1]; ++j);

        swap(nums[j-1], nums[i-1]);

        sort(nums.begin() + i, nums.end());
    }
};

int main() {
    Solution s;

    vector<vector<int> > input = {
        {1, 2, 3},
        {3, 2, 1},
        {1, 1, 5}
    };

    for (auto &item : input) {
        s.nextPermutation(item);
        for (auto &i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
