#include <string>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
private:
    long long _reverse(long long n) {
        if (n == 0) {
            return n;
        }

        bool positive = true;

        if (n < 0) {
            n = -n;
            positive = false;
        }

        long long result = 0;
        while (n) {
            result = result * 10 + n % 10;
            n /= 10;
        }

        if (!positive) {
            result = -result;
        }

        if (result > (long long)numeric_limits<int>::max()
            || result < (long long)numeric_limits<int>::min()) {
            return 0;
        } else {
            return result;
        }
    }
public:
    int reverse(int x) {
        return (int)_reverse(x);
    }
};
