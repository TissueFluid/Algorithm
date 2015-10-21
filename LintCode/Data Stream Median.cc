// Data Stream Median - heap

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

vector<int> medianII(vector<int> &nums) {
    vector<int> result;

    const int size = nums.size();

    if (size == 0) {
        return result;
    }

    int median = nums[0];
    priority_queue<int, vector<int>, less<int> > left;
    priority_queue<int, vector<int>, greater<int> > right;

    result.push_back(median);
    left.push(numeric_limits<int>::min());
    right.push(numeric_limits<int>::max());

    for (int i = 1; i < size; ++i) {
        if (left.size() == right.size()) {
            if (nums[i] > median) {
                right.push(nums[i]);
            } else {
                right.push(median);
                if (left.top() > nums[i]) {
                    median = left.top();
                    left.pop();
                    left.push(nums[i]);
                } else {
                    median = nums[i];
                }
            }
        } else {
            if (nums[i] > median) {
                left.push(median);
                if (right.top() > nums[i]) {
                    median = nums[i];
                } else {
                    median = right.top();
                    right.pop();
                    right.push(nums[i]);
                }
            } else {
                left.push(nums[i]);
            }
        }
        result.push_back(median);
    }

    return result;
}

int main() {
    vector<vector<int> > numss = {
        {1, 2, 3, 4, 5},
        {4, 5, 1, 3, 2, 6, 0},
        {5,-10,4}
    };

    for (auto &nums : numss) {
        auto result = medianII(nums);
        for (const auto &item : result) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
