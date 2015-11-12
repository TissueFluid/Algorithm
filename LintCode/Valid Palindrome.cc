// Valid Palindrome

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        const int len = s.length();

        int start = 0;
        int end = len - 1;

        while (start < end) {
            while (start < end && !isalnum(s[start])) {
                start++;
            }
            while (start < end && !isalnum(s[end])) {
                end--;
            }

            if (start < end) {
                char a = s[start];
                char b = s[end];
                if ((isdigit(a) && isdigit(b) && a == b)
                    || (isalpha(a) && isalpha(b) && tolower(a) == tolower(b))) {
                    start++;
                    end--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
