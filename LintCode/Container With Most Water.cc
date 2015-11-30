// Container With Most Water

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    inline int area(int left, int right, vector<int> &heights) {
        return (right - left) * min(heights[right], heights[left]);
    }
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        const int size = heights.size();

        if (size <= 1) {
            return 0;
        }

        int left = 0;
        int right = size - 1;
        int result = 0;

        while (left < right) {
            result = max(result, area(left, right, heights));
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};
