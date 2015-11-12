// Find the Missing Number

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        const int N = nums.size();

        for (int i = 0; i < N;) {
            if (nums[i] != 0) {
                if (i + 1 != nums[i]) {
                    swap(nums[nums[i] - 1], nums[i]);
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        int ret = 0;
        for (int i = 0; i < N; ++i) {
            if (nums[i] == 0) {
                ret = i + 1;
                break;
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> v({0, 1, 3});

    cout << s.findMissing(v) << endl;
    return 0;
}
