// Permutations

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void permuteWithoutRecursion(vector<int> &nums, vector<vector<int> > &result) {
    auto size = nums.size();
    stack<int> s;

    vector<int> indexes;

    for (size_t i = 0; i < size; ++i) {
        indexes.push_back(i);
    }

    while (1) {
        vector<int> permute;

        for (size_t j = 0; j < size; ++j) {
            permute.push_back(nums[indexes[j]]);
        }
        result.push_back(permute);

        int i;
        for (i = size - 1; i > 0 && indexes[i-1] >= indexes[i]; --i);

        if (i == 0) {
            break;
        }

        for (int j = size - 1; j >= i; j--) {
            if (indexes[j] > indexes[i-1]) {
                swap(indexes[j], indexes[i-1]);
                sort(indexes.begin() + i, indexes.end());
                break;
            }
        }
    }

    return;
}

void permuteWithRecursion(vector<int> &nums,
                          size_t start,
                          const size_t size,
                          vector<vector<int> > &result) {
    if (start == size) {
        result.push_back(nums);
        return;
    }

    for (size_t i = start; i < size; ++i) {
        swap(nums[i], nums[start]);
        permuteWithRecursion(nums, start + 1, size, result);
        swap(nums[start], nums[i]);
    }

    return;
}

vector<vector<int> > permute(vector<int> nums) {
    vector<vector<int> > result;

    if (nums.size() == 0) {
        return result;
    }

    // permuteWithRecursion(nums, 0, nums.size(), result);
    permuteWithoutRecursion(nums, result);

    return result;
}

int main() {
    vector<int> v = {1, 2, 3};
    auto result = permute(v);

    for (auto i : result) {
        cout << "[ ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
