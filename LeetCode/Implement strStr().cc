// Implement strStr()

#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int len_haystack = haystack.length();
        const int len_needle = needle.length();

        if (len_needle == 0) {
            return 0;
        }

        for (int i = 0; i < len_haystack - len_needle + 1; ++i) {
            int j;
            for (j = 0; j < len_needle; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == len_needle) {
                return i;
            }
        }

        return -1;
    }
};
