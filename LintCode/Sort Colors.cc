// Sort Colors

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        const int size = nums.size();
        int i = 0;
        int j = size - 1;

        for (int k = 0; k <= j; ) {
            while (nums[i] == 0) {
                i++;
                k++;
            }
            while (nums[j] == 2) {
                j--;
            }
            switch (nums[k]) {
            case 0:
                swap(nums[k], nums[i]);
                i++;
                k++;
                break;

            case 1:
                k++;
                break;

            case 2:
                swap(nums[k], nums[j]);
                j--;
                break;
            }
        }
    }
};

int main() {
    vector<int> v({1, 0, 1, 2});
    Solution s;;
    s.sortColors(v);

    for (const auto &item : v) {
        cout << item << endl;
    }
    return 0;
}
