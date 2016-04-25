// Restore IP Addresses

#include <string>
#include <vector>
using namespace std;

class Solution {
protected:
    inline bool valid(const string &s) {
        const int len = s.length();

        if (len == 1) {
            return true;
        }

        if (len == 2) {
            return s[0] != '0';
        }

        if (len == 3) {
            if (s[0] == '0') {
                return false;
            }
            auto value = stoi(s);
            if (0 <= value && value <= 255) {
                return true;
            }
        }

        return false;
    }

    void addToResult(vector<string> &tmp, vector<string> &result) {
        string str(tmp[0]);
        for (int i = 1; i <= 3; ++i) {
            str += "." + tmp[i];
        }
        result.push_back(str);
    }

    void helper(int n, const string &s, int start, const int &end,
                vector<string> &result) {
        static vector<string> tmp;

        if (start >= end) {
            return;
        }

        if (n == 1) {
            string last = s.substr(start);
            if (valid(last)) {
                tmp.push_back(last);
                addToResult(tmp, result);
                tmp.pop_back();
            }
            return;
        }

        for (int i = 0; i < 3 && start + i < end; ++i) {
            string substr = s.substr(start, i + 1);
            if (valid(substr)) {
                tmp.push_back(substr);
                helper(n - 1, s, start + i + 1, end, result);
                tmp.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        const int len = s.length();
        vector<string> result;

        if (len < 4 || len > 12) {
            return result;
        }

        helper(4, s, 0, len, result);
        return result;
    }
};
