// Contains Duplicate

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (const auto &num : nums) {
            if (s.find(num) == s.end()) {
                s.insert(num);
            } else {
                return true;
            }
        }

        return false;
    }
};
