// Scramble String

#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        const auto size = s1.length();
        if (size != s2.length()) {
            return false;
        }

        string tmp1(s1);
        string tmp2(s2);

        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());

        if (tmp1 != tmp2) {
            return false;
        }

        for (auto i = 1u; i < size; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
                && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(i))
                && isScramble(s1.substr(i), s2.substr(0, i))) {
                return true;
            }
        }

        return false;
    }
};
