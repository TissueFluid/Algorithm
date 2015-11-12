// Previous Permutation

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        vector<int> result(nums);
        const int size = nums.size();

        if (size == 0) {
            return result;
        }

        int i;
        for (i = size - 1; i > 0 && result[i] >= result[i - 1]; --i);

        if (i == 0) {
            reverse(result.begin(), result.end());
        } else {
            int j;
            for (j = i; j < size && result[j] < result[i - 1]; ++j);
            swap(result[j-1], result[i-1]);
            sort(result.begin() + i, result.end(), std::greater<int>());
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};

    auto res = s.previousPermuation(nums);

    for (auto item : res) {
        cout << item << endl;
    }

    return 0;
}
