// Trapping Rain Water

// 1. find Max
// 2. left to max : result += leftMax - current  (if > 0)
// 3. right to max: result += rightMax - current (if > 0)

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();

        int maxIndex = 0;
        for (int i = 1; i < N; ++i) {
            if (height[i] > height[maxIndex]) {
                maxIndex = i;
            }
        }

        int result = 0;

        int leftMax = 0;
        for (int i = 0; i < maxIndex; ++i) {
            if (height[i] > leftMax) {
                leftMax = height[i];
            } else {
                result += leftMax - height[i];
            }
        }

        int rightMax = 0;
        for (int i = N - 1; i > maxIndex; --i) {
            if (height[i] > rightMax) {
                rightMax = height[i];
            } else {
                result += rightMax - height[i];
            }
        }

        return result;
    }
};
