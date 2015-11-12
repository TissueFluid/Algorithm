// Add Binary

#include <iostream>
#include <string>

using namespace std;

#define VALUE_OF(ch) (ch - '0')

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        if (b.empty() || b == "") {
            return string(a);
        }

        if (a.empty() || a == "") {
            return string(b);
        }

        string longStr = a;
        string shortStr = b;

        if (longStr.length() < shortStr.length()) {
            longStr.swap(shortStr);
        }

        int lenShortStr = shortStr.length();
        int lenLongStr = longStr.length();
        int carry = 0;

        while (lenShortStr--) {
            lenLongStr--;
            longStr[lenLongStr] += (carry + VALUE_OF(shortStr[lenShortStr]));
            if (longStr[lenLongStr] > '1') {
                longStr[lenLongStr] -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        while (lenLongStr--) {
            longStr[lenLongStr] += carry;
            if (longStr[lenLongStr] > '1') {
                longStr[lenLongStr] -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if (carry == 1) {
            longStr = "1" + longStr;
        }

        return longStr;
    }
};

int main() {
    Solution s;
    string s1("11");
    string s2("1");

    cout << s.addBinary(s1, s2) << endl;
    return 0;
}
