// Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        vector<string> result;
        const auto len = digits.length();

        if (len == 0) {
            return result;
        }

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

        vector<int> solution;

        solution.push_back(0);

        while (!solution.empty()) {
            auto size = solution.size();

            if (solution.back() == m[digits[size - 1]].length()) {
                solution.pop_back();
                size--;
                if (size == 0) {
                    break;
                }
                solution[size - 1]++;
            } else {
                if (size < len) {
                    solution.push_back(0);
                } else {
                    string tmp;
                    for (int i = 0; i < len; ++i) {
                        tmp.push_back(m[digits[i]][solution[i]]);
                    }
                    result.push_back(tmp);

                    solution[size - 1]++;
                }
            }
        }

        return result;
    }
};
