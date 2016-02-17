// Remove Duplicates from Sorted Array

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Time: O(n)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int size = nums.size();

        if (size <= 1) {
            return size;
        }

        int cnt = 1;

        for (int i = 1; i < size; ++i) {
            if (nums[i] != nums[cnt - 1]) {
                nums[cnt] = nums[i];
                cnt++;
            }
        }

        nums.resize(cnt);

        return cnt;
    }
};

// Time: O(n)
// Space: O(1)
class Solution2 {
public:
    int removeDuplicates(vector<int> &nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};
