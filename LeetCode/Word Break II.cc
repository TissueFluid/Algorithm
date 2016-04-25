// Word Break II

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// 12ms
class Solution {
protected:
  int minLen;
  int maxLen;

  void dfs(const string &s, int start,
           const vector<vector<int> > &next,
           vector<string> &result) {
    static vector<int> answer;

    if (start == (int)(s.length())) {
      string tmp("");
      const int sizeOfAnswer = answer.size();

      for (int i = 0; i < sizeOfAnswer - 1; ++i) {
        tmp += s.substr(answer[i], answer[i + 1] - answer[i]) + " ";
      }
      tmp += s.substr(answer[sizeOfAnswer - 1]);
      result.push_back(tmp);
      return;
    }

    answer.push_back(start);
    for (const auto &item : next[start]) {
      dfs(s, item , next, result);
    }
    answer.pop_back();
  }
public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    const int LEN = s.length();
    const int numOfWords = wordDict.size();

    if (LEN == 0 || numOfWords == 0) {
      return {};
    }

    minLen = maxLen = wordDict.begin()->length();
    for (auto it = next(wordDict.begin(), 1); it != wordDict.end(); ++it) {
      minLen = min(minLen, (int)(it->length()));
      maxLen = max(maxLen, (int)(it->length()));
    }

    auto isWord = [&](const string &str) -> bool {
      return wordDict.find(str) != wordDict.end();
    };

    vector<bool> canBreak(LEN + 1, false);
    vector<vector<int> > next(LEN, vector<int>());
    canBreak[0] = true;

    for (int j = minLen - 1; j < LEN; ++j) {
      for (int i = max(0, j - maxLen + 1); i <= j - minLen + 1; ++i) {
        if (isWord(s.substr(i, j - i + 1))) {
          if (canBreak[i]) {
            canBreak[j + 1] = true;
            next[i].push_back(j + 1);
          }
        }
      }
    }

    if (!canBreak[LEN]) {
      return {};
    }

    vector<string> result;
    dfs(s, 0, next, result);

    return result;
  }
};

// 12ms
class Solution2 {
protected:
  int minLen;
  int maxLen;

  void dfs(const string &s, int start,
           const vector<vector<bool> > &isWord,
           vector<string> &result) {
    static vector<int> answer;
    if (start == (int)(s.length())) {
      string tmp("");
      const int sizeOfAnswer = answer.size();

      for (int i = 0; i < sizeOfAnswer - 1; ++i) {
        tmp += s.substr(answer[i], answer[i + 1] - answer[i]) + " ";
      }
      tmp += s.substr(answer[sizeOfAnswer - 1]);
      result.push_back(tmp);
      return;
    }

    int maxWordLen = min(maxLen, (int)(s.length()) - start);
    answer.push_back(start);
    for (auto wordLen = minLen; wordLen <= maxWordLen; ++wordLen) {
      if (isWord[start][start + wordLen - 1]) {
        dfs(s, start + wordLen, isWord, result);
      }
    }
    answer.pop_back();
  }
public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    const int LEN = s.length();
    const int numOfWords = wordDict.size();

    if (LEN == 0 || numOfWords == 0) {
      return {};
    }

    minLen = maxLen = wordDict.begin()->length();

    for (auto it = next(wordDict.begin(), 1); it != wordDict.end(); ++it) {
      minLen = min(minLen, (int)(it->length()));
      maxLen = max(maxLen, (int)(it->length()));
    }

    vector<vector<bool> > isWord(LEN, vector<bool>(LEN));
    vector<bool> dp(LEN + 1, false);
    dp[0] = true;
    auto check = [&](const string &str) -> bool {
      return wordDict.find(str) != wordDict.end();
    };

    for (int j = minLen - 1; j < LEN; ++j) {
      for (int i = max(0, j - maxLen + 1); i <= j - minLen + 1; ++i) {
        isWord[i][j] = check(s.substr(i, j - i + 1));
        if (isWord[i][j] && dp[i]) {
          dp[j+1] = true;
        }
      }
    }

    if (!dp[LEN]) {
      return {};
    }

    vector<string> result;
    dfs(s, 0, isWord, result);

    return result;
  }
};
