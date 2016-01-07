#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;

        const int size = nums.size();
        if (size < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        int target = 0;

        for (int i = 0; i < size - 2;) {
            int start = i + 1;
            int end = size - 1;

            if (nums[i] * 3 > target) {
                break;
            }

            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];

                if (sum == target) {
                    result.push_back({nums[i], nums[start], nums[end]});
                    if (nums[start] == nums[end]) {
                        break;
                    }
                    do {
                        start++;
                    } while (start < end && nums[start] == nums[start - 1]);
                    do {
                        end--;
                    } while (start < end && nums[end] == nums[end + 1]);
                } else if (sum < target) {
                    do {
                        start++;
                    } while (start < end && nums[start] == nums[start - 1]);
                } else {
                    do {
                        end--;
                    } while (start < end && nums[end] == nums[end + 1]);
                }
            }

            do {
                i++;
            } while (i < size - 2 && nums[i] == nums[i - 1]);
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v({7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6});

    auto res = s.threeSum(v);
    for (const auto &row : res) {
        for (const auto &item : row) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}
