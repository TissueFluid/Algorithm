// Permutations II

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

void permuteUniqueWithRecursion(vector<int> &nums,
                                size_t start,
                                const size_t size,
                                vector<vector<int> > &result) {
    if (start == size) {
        result.push_back(nums);
        return;
    }

    unordered_set<int> exists;

    for (size_t i = start; i < size; ++i) {
        if (exists.find(nums[i]) != exists.end()) {
            continue;
        } else {
            exists.insert(nums[i]);
        }
        swap(nums[i], nums[start]);
        permuteUniqueWithRecursion(nums, start + 1, size, result);
        swap(nums[i], nums[start]);
    }
}

void permuteUniqueWithoutRecursion(vector<int> &nums,
                                   vector<vector<int> > &result) {
    auto size = nums.size();
    sort(nums.begin(), nums.end());

    while (1) {
        result.push_back(nums);

        int i;
        for (i = size - 1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                break;
            }
        }

        if (i == 0) {
            break;
        }

        for (int j = size - 1; j >= i; j--) {
            if (nums[j] > nums[i-1]) {
                swap(nums[j], nums[i-1]);
                sort(nums.begin() + i, nums.end());
                break;
            }
        }
    }

    return;
}

vector<vector<int> > permuteUnique(vector<int> &nums) {
    vector<vector<int> > result;
    auto size = nums.size();

    if (size == 0) {
        return result;
    }

    // permuteUniqueWithRecursion(nums, 0, size, result);
    permuteUniqueWithoutRecursion(nums, result);

    return result;
}

int main() {
    vector<int> nums = {1, 1, 3};
    auto result = permuteUnique(nums);

    for (auto i : result) {
        cout << "[ ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
