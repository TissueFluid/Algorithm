// Subsets
//   Recursion

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsets(vector<int> &nums, unsigned start, unsigned size,
             vector<vector<int> > &result) {
    static vector<int> tmp;

    result.push_back(tmp);

    for (unsigned i = start; i < size; ++i) {
        tmp.push_back(nums[i]);
        subsets(nums, i + 1, size, result);
        tmp.pop_back();
    }

    return;
}

vector<vector<int> > subsets(vector<int> &nums) {
    vector<vector<int> > result;

    sort(nums.begin(), nums.end());
    subsets(nums, 0, nums.size(), result);

    return result;
}

int main() {
    vector<int> nums = {1,2,3};

    auto result = subsets(nums);

    for (auto i : result) {
        cout << "[ ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
