#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.length();

        if (len <= 1) {
            return s;
        }

        int start = 0;
        int longest = 1;

        for (int i = 0; i < len; ++i) {
            int left;
            int right;

            for (left = i-1, right = i+1;
                 left >= 0 && right < len && s[left] == s[right];
                 --left, ++right);

            int curr = right - left - 1;
            if (curr > longest) {
                longest = curr;
                start = left + 1;
            }

            for (left = i, right = i+1;
                 left >= 0 && right < len && s[left] == s[right];
                 --left, ++right);

            curr = right - left - 1;
            if (curr > longest) {
                longest = curr;
                start = left + 1;
            }
        }

        return s.substr(start, longest);
    }
};

// TLE solution
// isPal[i][j] = isPal[i + 1][j - 1] && s[i] == s[j]

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         const int len = s.length();

//         if (len == 0) {
//             return "";
//         }

//         vector<vector<bool> > isPal(len, vector<bool>(len));
//         int longest = 0;
//         int start = 0;

//         for (int i = len - 1; i >= 0; --i) {
//             for (int j = i; j < len; ++j) {
//                 if (i == j ||
//                     ((j == i+1 || isPal[i+1][j-1]) && s[i] == s[j])) {
//                     isPal[i][j] = true;
//                     if (j - i + 1 > longest) {
//                         longest = j - i + 1;
//                         start = i;
//                     }
//                 } else {
//                     isPal[i][j] = false;
//                 }
//             }
//         }

//         return s.substr(start, longest);
//     }
// };
