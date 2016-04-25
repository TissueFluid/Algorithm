// Word Ladder

// Two sides BFS

#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    if (beginWord == endWord) {
      return 0;
    }

    const int wordLen = beginWord.length();
    int result = 1;

    wordList.erase(beginWord);
    wordList.erase(endWord);

    unordered_set<string> begin({beginWord});
    unordered_set<string> end({endWord});

    auto &s1 = begin;
    auto &s2 = end;

    while (!s1.empty() && !s2.empty()) {
      ++result;
      if (s1.size() > s2.size()) {
        swap(s1, s2);
      }

      vector<string> next;

      for (auto &item : s1) {
        for (int i = 0; i < wordLen; ++i) {
          string str(item);
          for (int ch = 'a'; ch <= 'z'; ++ch) {
            str[i] = ch;

            if (s2.find(str) != s2.end()) {
              return result;
            }

            auto found = wordList.find(str);
            if (found != wordList.end()) {
              next.push_back(str);
              wordList.erase(found);
            }
          }
        }
      }

      s1.clear();
      copy(next.begin(), next.end(), std::inserter(s1, s1.end()));
    }

    return 0;
  }
};
