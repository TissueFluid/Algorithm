// Minimum Window Substring

#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        const int LEN_S = s.length();
        const int LEN_T = t.length();

        if (LEN_S == 0 || LEN_T == 0 || LEN_S < LEN_T) {
            return "";
        }

        int occurences[256] = {0};

        for (const auto &ch : t) {
            ++occurences[ch];
        }

        int left = 0;
        int count = 0;
        int minWindowStart = 0;
        int minWindowLen = LEN_S;
        bool found = false;

        for (int i = 0; i < LEN_S; ++i) {
            if (occurences[s[i]] > 0) {
                ++count;
            }

            --occurences[s[i]];

            if (count >= LEN_T) {
                found = true;
                while (count >= LEN_T) {
                    ++occurences[s[left]];

                    if (occurences[s[left]] > 0) {
                        --count;
                    }

                    ++left;
                }

                int windowLen = i - (left - 1) + 1;

                if (windowLen < minWindowLen) {
                    minWindowLen = windowLen;
                    minWindowStart = left - 1;
                }
            }
        }

        if (!found) {
            return "";
        }

        return s.substr(minWindowStart, minWindowLen);
    }
};
