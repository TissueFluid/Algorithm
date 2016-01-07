// Restore IP Addresses

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isValid(string s) {
        switch (s.length()) {
        case 1:
            return true;
        case 2:
            return s[0] != '0';
        case 3:
            return s[0] != '0' && stoi(s) < 256;
        default:
            return false;
        }

        return false;
    }

    string toIP(vector<string> &tmp) {
        string result(tmp[0]);

        for (int i = 1; i < tmp.size(); ++i) {
            result += "." + tmp[i];
        }

        return result;
    }

    void helper(string s, int n, vector<string> &result) {
        static vector<string> tmp;

        if (n == 4) {
            if (isValid(s)) {
                tmp.push_back(s);
                result.push_back(toIP(tmp));
                tmp.pop_back();
            }
        } else {
            for (int i = 1; i <= 3; i++) {
                if (i <= s.length() && isValid(s.substr(0, i))) {
                    tmp.push_back(s.substr(0, i));
                    helper(s.substr(i), n + 1, result);
                    tmp.pop_back();
                }
            }
        }
    }

public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        vector<string> result;

        helper(s, 1, result);

        return result;
    }
};
