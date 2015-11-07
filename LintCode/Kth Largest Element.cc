// Kth Largest Element

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int partition(vector<int> &nums, int start, int end) {
        int random = (start + end) / 2;

        swap(nums[start], nums[random]);

        for (int i = start + 1; i < end;) {
            if (nums[start] > nums[i]) {
                swap(nums[i], nums[--end]);
            } else {
                i++;
            }
        }

        swap(nums[start], nums[end - 1]);

        return end - 1;
    }

    int quickSelect(int k, vector<int> &nums, int start, int end) {
        int pivotIndex = partition(nums, start, end);

        if (pivotIndex + 1 == k) {
            return nums[pivotIndex];
        } else if (pivotIndex + 1 < k) {
            return quickSelect(k, nums, pivotIndex + 1, end);
        } else {
            return quickSelect(k, nums, start, pivotIndex);
        }
    }

    int kthLargestElement(int k, vector<int> nums) {
        const int size = nums.size();

        return quickSelect(k, nums, 0, size);
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    cout << s.kthLargestElement(3, {9, 3, 2, 4, 8}) << endl;
    cout << s.kthLargestElement(1, {1, 2, 3, 4, 5}) << endl;
    cout << s.kthLargestElement(2, {1, 2, 3, 4, 5}) << endl;
    cout << s.kthLargestElement(3, {1, 2, 3, 4, 5}) << endl;

    return 0;
}
