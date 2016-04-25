// Valid Palindrome

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int start = 0;
    int end = s.length() - 1;

    while (start <= end) {
      while (!isalnum(s[start]) && start <= end) {
        ++start;
      }

      if (start > end) {
        return true;
      }

      while (!isalnum(s[end]) && start <= end) {
        --end;
      }

      if (start > end) {
        return true;
      }

      if (isalpha(s[start]) && isalpha(s[end])) {
        if (toupper(s[start]) != toupper(s[end])) {
          return false;
        }
      } else {
        if (s[start] != s[end]) {
          return false;
        }
      }

      ++start;
      --end;
    }

    return true;
  }
};
