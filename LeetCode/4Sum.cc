#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int size = nums.size();

        if (size < 4) {
            return {};
        }

        sort(nums.begin(), nums.end());

        vector<vector<int> > result;

        for (int i = 0; i < size - 3; ) {
            if (nums[i] * 4 > target) {
                break;
            }

            for (int j = i + 1; j < size - 2; ) {
                int first_two = nums[i] + nums[j];

                if (first_two * 2 > target) {
                    break;
                }

                int start = j + 1;
                int end = size - 1;

                while (start < end) {
                    int sum = first_two + nums[start] + nums[end];

                    if (sum == target) {
                        result.push_back({nums[i],
                                    nums[j],
                                    nums[start],
                                    nums[end]});
                    }

                    if (sum <= target) {
                        do {
                            start++;
                        } while (start < end && nums[start] == nums[start - 1]);
                    }

                    if (sum >= target) {
                        do {
                            end--;
                        } while (start < end && nums[end] == nums[end + 1]);
                    }
                }

                do {
                    ++j;
                } while (j < size - 2 && nums[j] == nums[j - 1]);
            }

            do {
                ++i;
            } while (i < size - 3 && nums[i] == nums[i - 1]);
        }

        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int size = nums.size();

        if (size < 4) {
            return {};
        }

        // O(nlogn)
        sort(nums.begin(), nums.end());

        vector<vector<int> > result;
        unordered_map<int, vector<pair<int, int> > > m;

        // O(n^2)
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                m[nums[i] + nums[j]].push_back(make_pair(i, j));
            }
        }

        for (const auto &item : m) {
            if (item.first * 2 > target) {
                continue;
            }

            auto found = m.find(target - item.first);

            if (found != m.cend()) {
                int prev1_first = nums[item.second[0].first] - 1;
                int prev1_second = nums[item.second[0].second] - 1;

                for (const auto &pair1 : item.second) {
                    if (nums[pair1.first] == prev1_first
                        && nums[pair1.second] == prev1_second) {
                        continue;
                    }
                    prev1_first = nums[pair1.first];
                    prev1_second = nums[pair1.second];

                    int prev2_first = nums[found->second[0].first] - 1;
                    int prev2_second = nums[found->second[0].second] - 1;

                    for (const auto &pair2 : found->second) {
                        if (pair1.second < pair2.first) {
                            if (nums[pair2.first] == prev2_first
                                && nums[pair2.second] == prev2_second) {
                                continue;
                            }

                            prev2_first = nums[pair2.first];
                            prev2_second = nums[pair2.second];

                            result.push_back({nums[pair1.first],
                                        nums[pair1.second],
                                        nums[pair2.first],
                                        nums[pair2.second]
                                        });
                        }
                    }
                }
            }
        }

        return result;
    }
};
