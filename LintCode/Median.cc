// Median

// When quick selecting, either i++ or end--

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int findKth(int left, int right, int k, vector<int> &nums) {
        if (left == right) {
            return nums[left];
        }

        int random = (left + right) / 2;

        swap(nums[left], nums[random]);

        int end = right;
        for (int i = left + 1; i < end;) {
            if (nums[i] > nums[left]) {
                swap(nums[i], nums[--end]);
            } else {
                i++;
            }
        }

        swap(nums[left], nums[end - 1]);

        if (end - 1 == k) {
            return nums[k];
        } else if (end - 1 < k) {
            return findKth(end, right, k, nums);
        } else {
            return findKth(left, end - 1, k, nums);
        }
    }
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        const int size = nums.size();

        if (size == 0) {
            return -1;
        }

        return findKth(0, size, (size + 1) / 2 - 1, nums);
    }
};

int main() {
    Solution s;

    vector<int> v({4, 5, 1, 2, 3});
    cout << s.median(v) << endl;
    return 0;
}
