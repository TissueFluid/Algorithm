// Sort Colors

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int size = nums.size();

        int mostLeftOne = -1;
        int mostRightThree = size;

        for (int i = 0; i < mostRightThree; ++i) {
            switch (nums[i]) {
            case 0:
                ++mostLeftOne;
                swap(nums[i], nums[mostLeftOne]);
                break;
            case 1:
                break;
            case 2:
                --mostRightThree;
                swap(nums[i], nums[mostRightThree]);
                --i;
                break;
            default:
                break;
            }
        }
    }
};
