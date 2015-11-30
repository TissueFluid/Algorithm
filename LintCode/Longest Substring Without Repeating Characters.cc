// Longest Substring Without Repeating Characters

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string s) {
        const int size = s.length();

        if (size == 0) {
            return 0;
        }

        int result = 1;
        int slow = 0;
        int fast;
        vector<int> hash(256, -1);

        for (fast = 0; fast < size; ++fast) {
            int ch = s[fast];

            if (hash[ch] >= slow) {
                result = max(result, fast - slow);
                slow = hash[ch] + 1;
            }

            hash[ch] = fast;
        }

        return max(result, fast - slow);
    }
};
