// Largest Rectangle in Histogram
//   Stack

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int> &height) {
    auto size = height.size();

    if (size == 0) {
        return 0;
    }

    stack<int> s;

    int largest = 0;
    height.push_back(0);

    for (int i = 0; i < size + 1; ++i) {
        int top;
        while (!s.empty() && height[top = s.top()] >= height[i]) {
            s.pop();
            int width = s.empty() ? i : (i - 1 - s.top());
            largest = max(largest, width * height[top]);
        }
        s.push(i);
    }

    height.pop_back();

    return largest;
}

int main() {
    vector<int> v({2,1,5,6,2,3});
    cout << largestRectangleArea(v) << endl;
    return 0;
}
