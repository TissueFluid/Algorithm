// Largest Rectangle in Histogram

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int size = heights.size();

        if (size == 0) {
            return 0;
        }

        stack<int> s;
        int top;
        int largest = 0;

        heights.push_back(0);

        for (int i = 0; i < size + 1; ++i) {
            while (!s.empty() && heights[top = s.top()] >= heights[i]) {
                s.pop();
                largest = max(largest, heights[top] * (s.empty() ? i : i - 1 - s.top()));
            }
            s.push(i);
        }

        return largest;
    }
};
