// Remove Duplicates from Sorted Array II

#include <iostream>
#include <vector>
using namespace std;

// Time: O(n)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int size = nums.size();

        if (size <= 2) {
            return size;
        }

        const int occur = 2;
        int cnt = occur;

        for (int i = occur; i < size; ++i) {
            if (nums[i] != nums[cnt - occur]) {
                nums[cnt] = nums[i];
                cnt++;
            }
        }

        nums.resize(cnt);

        return cnt;
    }
};
