// Longest Consecutive Sequence

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    auto isUsed = [&s](const int &num) -> bool {
      return s.find(num) == s.end();
    };

    auto markAsUsed = [&s](const int &num) {
      s.erase(num);
    };

    int result = 0;

    for (const auto &item : nums) {
      if (isUsed(item)) {
        continue;
      }

      int length = 1;

      for (int i = item + 1; !isUsed(i); ++i) {
        ++length;
        markAsUsed(i);
      }

      for (int i = item - 1; !isUsed(i); --i) {
        ++length;
        markAsUsed(i);
      }

      result = max(result, length);

      if (s.empty()) {
        break;
      }
    }

    return result;
  }
};
