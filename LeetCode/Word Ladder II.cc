// Word Ladder II

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    if (beginWord == endWord) {
      return {
        {beginWord, endWord}
      };
    }

    const int wordLen = beginWord.length();

    unordered_set<string> begin({beginWord});
    unordered_set<string> end({endWord});
    unordered_set<string> &s1 = begin;
    unordered_set<string> &s2 = end;
    bool reverse = false;
    bool found = false;
    int count = 1;

    unordered_map<string, unordered_set<string> > next;

    auto makeNext = [&](const string &prev, const string &curr) {
      if (reverse) {
        next[curr].insert(prev);
      } else {
        next[prev].insert(curr);
      }
    };

    while (!begin.empty() && !end.empty()) {
      ++count;
      if (s1.size() > s2.size()) {
        swap(s1, s2);
        reverse = !reverse;
      }

      for (const auto &item : s1) {
        wordList.erase(item);
      }

      for (const auto &item : s2) {
        wordList.erase(item);
      }

      unordered_set<string> nextlevel;

      for (const auto &item : s1) {
        string tmp(item);
        for (int i = 0; i < wordLen; ++i) {
          auto backup = tmp[i];
          for (int j = 'a'; j <= 'z'; ++j) {
            tmp[i] = j;
            if (s2.find(tmp) != s2.end()) {
              makeNext(item, tmp);
              found = true;
            } else if (!found && wordList.find(tmp) != wordList.end()) {
              makeNext(item, tmp);
              nextlevel.insert(tmp);
            }
          }
          tmp[i] = backup;
        }
      }

      if (found) {
        break;
      }

      s1.clear();
      copy(nextlevel.begin(), nextlevel.end(), std::inserter(s1, s1.end()));
    }

    if (found) {
      vector<string> tmp({beginWord});
      vector<vector<string> > result;
      dfs(endWord, next, tmp, result, count);
      return result;
    }

    return {};
  }

protected:
  void dfs(const string &end,
           const unordered_map<string, unordered_set<string> > &next,
           vector<string> &tmp,
           vector<vector<string> > &result,
           const int &count) {
    if (tmp.size() == count) {
      if (tmp.back() == end) {
        result.push_back(tmp);
      }
      return;
    }

    auto nextWords = next.find(tmp.back());

    if (nextWords != next.end()) {
      for (const auto &item : nextWords->second) {
        tmp.push_back(item);
        dfs(end, next, tmp, result, count);
        tmp.pop_back();
      }
    }
  }
};
