// Substring with Concatenation of All Words

// sliding window

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (words.empty() || s.empty() || s == "") {
            return result;
        }

        unordered_map<string, int> mapWordToOccurences;

        for (const auto &word : words) {
            if (mapWordToOccurences.find(word) == mapWordToOccurences.end()) {
                mapWordToOccurences[word] = 1;
            } else {
                mapWordToOccurences[word]++;
            }
        }

        const int wordLen = words[0].length();
        const int strLen = s.length();
        const int wordsNum = words.size();

        for (int i = 0; i < wordLen; ++i) {
            int count = 0;
            unordered_map<string, int> slidingWindow;

            for (int j = i; j + wordLen <= strLen; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (mapWordToOccurences.find(word) == mapWordToOccurences.end()) {
                    slidingWindow.clear();
                    count = 0;
                } else {
                    if (slidingWindow.find(word) == slidingWindow.end()) {
                        slidingWindow[word] = 1;
                    } else {
                        slidingWindow[word]++;
                    }
                    count++;

                    while (slidingWindow[word] > mapWordToOccurences[word]) {
                        slidingWindow[s.substr(j - (count-1) * wordLen, wordLen)]--;
                        count--;
                    }

                    if (count == wordsNum) {
                        result.push_back(j - (count-1) * wordLen);
                    }
                }
            }
        }

        return result;
    }
};
