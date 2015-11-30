// Longest Palindromic Substring

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        const int length = s.length();

        if (length == 0) {
            return "";
        }

        vector<vector<bool> > isPal(length, vector<bool>(length, false));

        int start = 0;
        int max = -1;

        for (int j = 0; j < length; ++j) {
            for (int i = 0; i <=j ; ++i) {
                if (i == j) {
                    isPal[i][j] = true;
                } else if (i + 1 == j) {
                    isPal[i][j] = (s[i] == s[j]);
                } else {
                    isPal[i][j] = (isPal[i+1][j-1] && s[i] == s[j]);
                }

                if (isPal[i][j]) {
                    if (j - i + 1 > max) {
                        max = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, max);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str("abcdzdcab");

    cout << s.longestPalindrome(str) << endl;
    return 0;
}
