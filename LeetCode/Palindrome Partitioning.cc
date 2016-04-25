// Palindrome Partitioning

#include <vector>
#include <string>
using namespace std;

class Solution {
protected:
  void dfs(const string &s,
           const vector<vector<bool> > &isPal,
           const int start, const int end,
           vector<vector<string> > &result) {
    static vector<string> tmp;
    if (start == end) {
      result.push_back(tmp);
      return;
    }

    for (int i = start; i < end; ++i) {
      if (isPal[start][i]) {
        tmp.push_back(s.substr(start, i - start + 1));
        dfs(s, isPal, i + 1, end, result);
        tmp.pop_back();
      }
    }
  }
public:
  vector<vector<string>> partition(string s) {
    const int LEN = s.length();

    if (LEN == 0) {
      return {};
    }

    vector<vector<bool> > isPal(LEN, vector<bool>(LEN, false));
    for (int i = LEN - 1; i >= 0; --i) {
      for (int j = i; j < LEN; ++j) {
        if (j > i + 1) {
          isPal[i][j] = isPal[i+1][j-1] && s[i] == s[j];
        } else {
          isPal[i][j] = s[i] == s[j];
        }
      }
    }

    vector<vector<string> > result;
    dfs(s, isPal, 0, LEN, result);

    return result;
  }
};
