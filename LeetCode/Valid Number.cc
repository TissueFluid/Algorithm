// Valid Number

#include <string>
#include <ctype.h>
using namespace std;

class Solution {
    void trimSpaces(string &s) {
        const int len = s.length();

        int start, end;

        for (start = 0; start < len && s[start] == ' '; ++start);

        if (start == len) {
            return;
        }

        for (end = len - 1; start <= end && s[end] == ' '; --end);

        if (start > end) {
            return;
        }

        s = s.substr(start, end - start + 1);
    }

    bool valid(const string &s, bool hasDot = true) {
        const int len = s.length();

        if (len == 0) {
            return false;
        }

        if (s == ".") {
            return false;
        }

        int count = 0;

        for (int i = 0; i < len; ++i) {
            if (!isdigit(s[i])) {
                if (s[i] == '.') {
                    if (!hasDot) {
                        return false;
                    }
                    count++;
                    if (count > 1) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    void removeSign(string &s) {
        const int len = s.length();
        if (len == 0) {
            return;
        }

        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
    }

public:
    bool isNumber(string s) {
        trimSpaces(s);

        if (s == "") {
            return false;
        }

        auto found = s.find('e');

        if (found == string::npos) {
            removeSign(s);
            return s != "." && valid(s);
        }

        string part1 = s.substr(0, found);
        string part2 = s.substr(found + 1);

        removeSign(part1);
        removeSign(part2);

        return valid(part1) && valid(part2, false);
    }
};
