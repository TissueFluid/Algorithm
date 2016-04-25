// Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int mid;
        int factor;

        while (left <= right) {
            mid = left + ((right - left) >> 1);
            factor = x / mid;

            if (factor == mid) {
                return mid;
            } else if (factor > mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};
