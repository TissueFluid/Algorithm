// Divide Two Integers

#include <cstdlib>
#include <limits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return numeric_limits<int>::max();
        }
        bool positive = true;
        long long ll_dividend = llabs(dividend);
        long long ll_divisor = llabs(divisor);

        if ((dividend < 0 && divisor > 0)
            || (dividend > 0 && divisor < 0)) {
            positive = false;
        }

        int n_shift = 1;

        while ((ll_divisor << n_shift) <= ll_dividend) {
            n_shift++;
        }

        n_shift--;

        long long int result = 0;

        while (n_shift >= 0 && ll_dividend > 0) {
            long long int tmp = ll_divisor << n_shift;
            if (ll_dividend >= tmp) {
                ll_dividend -= tmp;
                result += ((long long)1 << n_shift);
            }

            n_shift--;
        }

        if (!positive) {
            result = -result;
        }

        if (result > (long long)numeric_limits<int>::max()
            || result < (long long)numeric_limits<int>::min()) {
            return numeric_limits<int>::max();
        }

        return result;
    }
};
