// Partition Array by Odd and Even

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        const int size = nums.size();

        int i = 0;
        int j = size - 1;

        while (i < j) {
            while (nums[i] % 2 == 1 && i < j) {
                i++;
            }
            while (nums[j] % 2 == 0 && i < j) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4};
    Solution s;

    s.partitionArray(v);

    for (auto const &item : v) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
