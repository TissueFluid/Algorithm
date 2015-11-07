// Palindrome Partitioning

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        const int len = s.length();

        if (len == 0) {
            return result;
        }

        vector<vector<bool> > isPal(len, vector<bool>(len, false));

        for (int j = 0; j < len; ++j) {
            for (int i = 0; i <= j; ++i) {
                if ((i >= j - 1 || isPal[i + 1][j - 1]) && s[i] == s[j]) {
                    isPal[i][j] = true;
                }
            }
        }

        vector<int> tmp;
        tmp.push_back(0);
        int i = 0;

        while (!tmp.empty()) {
            if (i == len) {
                // the end
                if (tmp.back() == len) {
                    // find one
                    vector<string> row;
                    for (size_t j = 1; j < tmp.size(); ++j) {
                        row.push_back(s.substr(tmp[j-1], tmp[j] - tmp[j-1]));
                    }
                    result.push_back(row);
                }

                i = tmp.back();
                tmp.pop_back();
            } else {
                // not the end
                if (isPal[tmp.back()][i]) {
                    tmp.push_back(i + 1);
                }
                i++;
            }
        }

        return result;
    }
};


int main() {
    Solution s;

    auto result = s.partition("aab");

    for (const auto &item : result) {
        for (const auto &str : item) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
