// Length of Last Word

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        const int len = s.length();

        int i = len - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        if (i < 0) {
            return 0;
        }

        int end = i;

        while (i >= 0 && s[i] != ' ') {
            i--;
        }

        return end - i;
    }
};
