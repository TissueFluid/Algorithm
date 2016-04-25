// Word Break
// for k from max(0, i - maxWordLen) to i - minWordLen
// dp[i] = dp[k] && canBreak(k + 1, i)

#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    const int LEN = s.length();
    const int numOfWords = wordDict.size();

    if (LEN == 0) {
      return true;
    }

    if (numOfWords == 0) {
      return false;
    }

    int maxLen;
    int minLen;

    maxLen = minLen = wordDict.begin()->length();

    for (auto it = next(wordDict.begin(), 1); it != wordDict.end(); ++it) {
      maxLen = max(maxLen, (int)(it->length()));
      minLen = min(minLen, (int)(it->length()));
    }

    vector<bool> canBreak(LEN, false);
    auto isWord = [&](const string &str) -> bool {
      return wordDict.find(str) != wordDict.end();
    };

    for (int i = minLen - 1; i < LEN; ++i) {
      canBreak[i] = i + 1 <= maxLen && isWord(s.substr(0, i + 1));
      for (int j = max(0, i - maxLen); j <= i - minLen && !canBreak[i]; ++j) {
        if (canBreak[j]) {
          canBreak[i] = isWord(s.substr(j + 1, i - j));
        }
      }
    }

    return canBreak[LEN - 1];
  }
};
