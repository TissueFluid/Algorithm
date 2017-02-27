class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            auto found = m.find(target - nums[i]);

            if (found != end(m)) {
                return {found->second, i};
            }

            m[nums[i]] = i;
        }

        return {};
    }
};
