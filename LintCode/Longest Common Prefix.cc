#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
  if (strs.size() == 0) {
    return string("");
  }
  if (strs.size() == 1) {
    return strs[0];
  }

  unsigned long minLen = strs[0].length();
  int i;

  for (i = 1; i < strs.size(); ++i) {
    minLen = min(strs[i].length(), minLen);
  }

  if (minLen == 0) {
    return string("");
  }

  int left = -1;
  int right = minLen;
  int mid = (left + right) / 2;

  while (left < mid) {
    for (i = 1; i < strs.size(); i++) {
      if (strs[i][mid] != strs[i-1][mid]) {
        break;
      }
    }
    if (i != strs.size()) {
      right = mid;
    } else {
      left = mid;
    }
    mid = (right + left) / 2;
  }

  if (left == -1) {
    return string("");
  } else {
    return strs[0].substr(0, left + 1);
  }
}

int main(int argc, char const* argv[])
{
  vector<string> a;
  a.push_back(string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
  a.push_back(string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
  a.push_back(string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
  cout << longestCommonPrefix(a) << endl;
  return 0;
}
