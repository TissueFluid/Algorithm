// Valid Number

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
private:
    static bool oneDot(string &s) {
        int count = 0;
        for (auto ch : s) {
            if (!isdigit(ch)) {
                if (ch == '.') {
                    if (count >= 1) {
                        return false;
                    }
                    count++;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        const int len = s.length();
        int start = 0;
        int end = len - 1;

        while (start <= end && s[start] == ' ') {
            start++;
        }

        while (start <= end && s[end] == ' ') {
            end--;
        }

        if (start > end) {
            return false;
        }

        if (s[start] == '+' || s[start] == '-') {
            start++;
            if (start > end) {
                return false;
            }
        }

        string tmp = s.substr(start, end - start + 1);

        auto found = tmp.find('e');
        if (found == string::npos) {
            return tmp != "." && oneDot(tmp);
        } else {
            string part1 = tmp.substr(0, found);
            string part2 = tmp.substr(found + 1);

            if (part1 == "" || part2 == "") {
                return false;
            }

            if (part1 == "." || part2 == ".") {
                return false;
            }

            return oneDot(part1) && oneDot(part2);
        }
    }
};
