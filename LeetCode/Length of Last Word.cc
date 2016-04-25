// Length of Last Word

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        const int LEN = s.length();

        int count = 0;
        int i;

        for (i = LEN - 1; i >= 0 && s[i] == ' '; --i);
        for (; i >= 0 && s[i] != ' '; --i, count++);

        return count;
    }
};
