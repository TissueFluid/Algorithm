#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        const int len = s.length();

        if (len <= 1) {
            return len;
        }

        int slow = 0;
        int fast = 0;
        int result = 0;

        vector<int> pos(256, -1);

        for (; fast < len; ++fast) {
            if (pos[s[fast]] >= slow) {
                result = max(result, fast - slow);
                slow = pos[s[fast]] + 1;
            }
            pos[s[fast]] = fast;
        }

        return max(result, fast - slow);
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        const int len = s.length();

        if (len <= 1) {
            return len;
        }

        int slow = 0;
        int fast = 0;
        int result = 0;

        vector<bool> exist(256, false);

        for (; fast < len; ++fast) {
            if (exist[s[fast]] == false) {
                exist[s[fast]] = true;
            } else {
                result = max(result, fast - slow);
                for (; slow < fast; ++slow) {
                    if (s[slow] == s[fast]) {
                        slow++;
                        break;
                    }
                    exist[s[slow]] = false;
                }
            }
        }

        return max(result, fast - slow);
    }
};
