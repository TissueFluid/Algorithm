// Post Office Problem

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool _isScramble(string s1, string s2) {
        const int length = s1.length();

        if (length == 1) {
            return s1[0] == s2[0];
        }

        if (s1 == s2) {
            return true;
        }

        for (int i = 1; i < length; ++i) {
            if (_isScramble(s1.substr(0, i), s2.substr(0, i))
                && _isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }

            if (_isScramble(s1.substr(0, i), s2.substr(length - i))
                && _isScramble(s1.substr(i), s2.substr(0, length - i))) {
                return true;
            }
        }

        return false;
    }
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        const int length = s1.length();
        if (length != s2.length()) {
            return false;
        }

        if (length == 0) {
            return true;
        }

        return _isScramble(s1, s2);
    }
};
