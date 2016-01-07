#include <vector>
using namespace std;

class Solution {
private:
    int findKth(const vector<int> &nums1, int end1,
                const vector<int> &nums2, int end2,
                int k) {
        if (end1 == 0) {
            return nums2[end2 - k];
        }

        if (end2 == 0) {
            return nums1[end1 - k];
        }

        if (k == 1) {
            return max(nums1[end1 - 1], nums2[end2 - 1]);
        }

        if (end1 - k/2 < 0 ||
            (end2 - k/2 >= 0 && nums2[end2 - k/2] > nums1[end1 - k/2])) {
            return findKth(nums1, end1, nums2, end2 - k/2, k - k/2);
        } else {
            return findKth(nums1, end1 - k/2, nums2, end2, k - k/2);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int size1 = nums1.size();
        const int size2 = nums2.size();
        const int N = size1  + size2;

        if (N % 2 == 1) { // odd
            return (double)findKth(nums1, size1, nums2, size2, N / 2 + 1);
        } else { // even
            return (
                (double)findKth(nums1, size1, nums2, size2, N / 2 + 1) +
                (double)findKth(nums1, size1, nums2, size2, N / 2)
                ) / 2.0;
        }
    }
};
