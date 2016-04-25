// Text Justification

#include <vector>
#include <string>
using namespace std;

class Solution {
    void addToResult(const int maxWidth,
                     int &length, int &count,
                     const vector<string> &words,
                     vector<int> &wordsInALine,
                     vector<string> &result) {
        if (count == 1) {
            result.push_back(words[wordsInALine[0]] + string(maxWidth - length, ' '));
        } else {
            const int spaces = maxWidth - length;
            const int interval = spaces / (count - 1) + 1;
            int remainder = spaces % (count - 1);
            string tmp(words[wordsInALine[0]]);

            for (int j = 1; j < count; ++j) {
                tmp += string(interval, ' ');
                if (remainder > 0) {
                    tmp += ' ';
                    --remainder;
                }
                tmp += words[wordsInALine[j]];
            }
            result.push_back(tmp);
        }

        count = 0;
        length = 0;
        wordsInALine.clear();
    }

    void addLastLineToResult(const int maxWidth,
                             int &length, int &count,
                             const vector<string> &words,
                             vector<int> &wordsInALine,
                             vector<string> &result) {
        if (count == 0) {
            result.push_back(string(maxWidth - 1, ' '));
            return;
        }

        string tmp(words[wordsInALine[0]]);

        for (int i = 1; i < count; ++i) {
            tmp += (" " + words[wordsInALine[i]]);
        }

        tmp += string(maxWidth - length, ' ');
        result.push_back(tmp);
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (maxWidth == 0) {
            return {string("")};
        }

        ++maxWidth;
        const int numOfWords = words.size();
        vector<string> result;
        vector<int> wordsInALine;
        int count = 0;
        int length = 0;

        for (int i = 0; i < numOfWords; ++i) {
            const int len = words[i].length();

            if (len == 0) {
                continue;
            }

            if ((maxWidth - length) < (len + 1)) {
                addToResult(maxWidth, length, count, words, wordsInALine, result);
            }

            wordsInALine.push_back(i);
            length += len + 1;
            count++;
        }

        addLastLineToResult(maxWidth, length, count, words, wordsInALine, result);

        return result;
    }
};
