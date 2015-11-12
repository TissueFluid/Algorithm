// Roman ot Interger

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        if (s.empty() || s.length() == 0) {
            return 0;
        }

        unordered_map<char, int> m;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int result = m[s.back()];

        for (int i = s.length() - 2; i >= 0; --i) {
            if (m[s[i]] >= m[s[i + 1]]) {
                result += m[s[i]];
            } else {
                result -= m[s[i]];
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    string str("DCXXI");
    cout << s.romanToInt(str) << endl;
    return 0;
}
