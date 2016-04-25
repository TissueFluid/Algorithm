// Merge Sorted Array

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m > 0 && n > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[m + n - 1] = nums1[m - 1];
                --m;
            } else {
                nums1[m + n - 1] = nums2[n - 1];
                --n;
            }
        }

        copy(nums2.begin(), nums2.begin() + n, nums1.begin());
    }
};
