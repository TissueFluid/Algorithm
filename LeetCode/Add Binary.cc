// Add Binary

#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (b.length() > a.length()) {
            swap(a, b);
        }

        const int len_a = a.length();
        const int len_b = b.length();

        int i = len_a - 1;
        int j = len_b - 1;

        int c = 0;
        for (; j >= 0; --j, --i) {
            a[i] += (b[j] - '0' + c);
            if (a[i] > '1') {
                a[i] -= 2;
                c = 1;
            } else {
                c = 0;
            }
        }

        for (; c && i >= 0; --i) {
            a[i] += c;
            if (a[i] > '1') {
                a[i] -= 2;
                c = 1;
            } else {
                c = 0;
            }
        }

        if (c == 1) {
            a = '1' + a;
        }

        return a;
    }
};
