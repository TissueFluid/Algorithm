// Trapping Rain Water

// Find the heighest, use two pointers from both sides

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        const int size = heights.size();

        if (size == 0) {
            return 0;
        }

        int maxIndex;
        int maxHeight = heights[0];
        for (int i = 1; i < size; ++i) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
                maxIndex = i;
            }
        }

        int result = 0;

        maxHeight = 0;
        for (int i = 0; i < maxIndex; ++i) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
            } else {
                result += (maxHeight - heights[i]);
            }
        }

        maxHeight = 0;
        for (int i = size - 1; i > maxIndex; --i) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
            } else {
                result += (maxHeight - heights[i]);
            }
        }

        return result;
    }
};
