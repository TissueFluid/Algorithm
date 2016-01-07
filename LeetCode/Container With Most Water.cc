#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        const int size = height.size();

        if (size < 2) {
            return 0;
        }

        int left = 0;
        int right = size - 1;
        int result = 0;

        while (left < right) {
            result = max(result,
                         (right - left) * min(height[right], height[left]));

            int prev_left = height[left];
            int prev_right = height[right];

            if (prev_left <= prev_right) {
                do {
                    left++;
                } while (left < right && height[left] <= prev_left);
            }

            if (prev_left >= prev_right) {
                do {
                    right--;
                } while (left < right && height[right] <= prev_right);
            }

        }

        return result;
    }
};
