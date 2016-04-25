// Maximal Rectangle
//  - largestRectangle

#include <vector>
#include <stack>
using namespace std;

class Solution {
protected:
    int largestRectangle(const vector<int> &heights) {
        int largest = 0;
        int top;
        const int size = heights.size();
        stack<int> s;

        for (int i = 0; i < size; ++i) {
            while (!s.empty() && heights[top = s.top()] >= heights[i]) {
                s.pop();
                largest = max(largest, heights[top] * (s.empty() ? i : i - 1 - s.top()));
            }
            s.push(i);
        }

        return largest;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int height = matrix.size();

        if (height == 0) {
            return 0;
        }

        const int width = matrix[0].size();

        if (width == 0) {
            return 0;
        }

        vector<int> heights(width + 1, 0);
        int result = 0;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j] += 1;
                }
            }
            result = max(result, largestRectangle(heights));
        }

        return result;
    }
};
