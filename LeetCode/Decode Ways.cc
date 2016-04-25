// Decode Ways


// DP
//   dp[i] = dp[i-1] + canDecode(s[i-1:i]) ? dp[i-2] : 0;

#include <string>
using namespace std;


class Solution {
protected:
    inline bool canDecode2(const string &s, int i) {
        return (s[i - 1] == '1')
            || (s[i - 1] == '2' && s[i] <= '6');
    }
    inline bool canDecode1(const string &s, int i) {
        return s[i] >= '1' && s[i] <= '9';
    }
public:
    int numDecodings(string s) {
        const int size = s.length();

        if (size == 0) {
            return 0;
        }

        int a, b, c;

        a = (canDecode1(s, 0) ? 1 : 0);

        if (size == 1) {
            return a;
        }

        b = (canDecode1(s, 1) ? a : 0) + (canDecode2(s, 1) ? 1 : 0);

        if (size == 2) {
            return b;
        }

        for (int i = 2; i < size; ++i) {
            c = (canDecode1(s, i) ? b : 0) + (canDecode2(s, i) ? a : 0);
            a = b;
            b = c;
        }

        return c;
    }
};
