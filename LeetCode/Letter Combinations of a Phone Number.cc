#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
    void helper(int start, const string &digits,
                vector<string> &result,
                const unordered_map<char, string> &m) {
        static string tmp("");

        if (start == (int)digits.length()) {
            result.push_back(tmp);
            return;
        }

        for (const auto &ch : m.at(digits[start])) {
            tmp.push_back(ch);
            helper(start + 1, digits, result, m);
            tmp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        const int len = digits.length();
        if (digits.empty() || len == 0) {
            return {};
        }

        vector<string> result;

        const unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        helper(0, digits, result, m);

        return result;
    }
};


class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
        const int len = digits.length();
        if (digits.empty() || len == 0) {
            return {};
        }

        vector<string> result;

        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<int> tmp;

        tmp.push_back(0);

        while (!tmp.empty()) {
            const auto &chars = m[digits[tmp.size() - 1]];

            if (tmp.back() >= chars.length()) {
                tmp.pop_back();
                if (!tmp.empty()) {
                    tmp.back()++;
                }
            } else {
                if (tmp.size() < len) {
                    tmp.push_back(0);
                } else {
                    string one("");

                    for (int i = 0; i < len; ++i) {
                        one.push_back(m[digits[i]][tmp[i]]);
                    }
                    result.push_back(one);

                    tmp.back()++;
                }
            }
        }

        return result;
    }
};
