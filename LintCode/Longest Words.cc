// Longest Words

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        const int size = dictionary.size();
        vector<int> tmp;
        size_t max = 0;

        for (int i = 0; i < size; ++i) {
            auto len = dictionary[i].length();

            if (len == max) {
                tmp.push_back(i);
            } else if (len > max) {
                max = len;
                tmp.clear();
                tmp.push_back(i);
            }
        }

        vector<string> result;
        for (const auto &item : tmp) {
            result.push_back(dictionary[item]);
        }

        return result;
    }
};
