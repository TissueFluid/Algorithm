// Divide Two Integers

// Notice cast to long long

#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        long long lldividend = dividend;
        long long lldivisor = divisor;
        long long result = 0;

        bool positive = true;

        if (lldividend < 0) {
            positive = !positive;
            lldividend = -lldividend;
        }

        if (lldivisor < 0) {
            positive = !positive;
            lldivisor = -lldivisor;
        }

        while (lldividend >= lldivisor) {
            long long shift = 0;
            while (lldividend >= (lldivisor << shift)) {
                shift++;
            }
            lldividend -= (lldivisor << (shift - 1));
            result += ((long long)1 << (shift - 1));
        }

        if (!positive) {
            result = -result;
        }

        if (result > (long long)numeric_limits<int>::max()
            || result < (long long)numeric_limits<int>::min()) {
            return 2147483647;
        }

        return (int)result;
    }
};

int main() {
    Solution s;
    cout << s.divide(-2147483648, -1) << endl;
    return 0;
}
