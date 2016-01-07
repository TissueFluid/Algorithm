#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty() || s.length() == 0) {
            return -1;
        }

        unordered_map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = m[s[s.length() - 1]];

        for (int i = s.length() - 2; i >= 0; --i) {
            if (m[s[i]] >= m[s[i + 1]]) {
                result += m[s[i]];
            } else {
                result -= m[s[i]];
            }
        }

        return result;
    }
};
