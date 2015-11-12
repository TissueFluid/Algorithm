// Easy Reverse Integer

#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        if (n == 0) {
            return 0;
        }

        bool positive = true;

        if (n < 0) {
            n = -n;
            positive = false;
        }

        long long result = 0;

        while (n) {
            result *= 10;
            result += n % 10;
            n /= 10;
        }

        if (!positive) {
            result = -result;
        }

        if (result > (long long)numeric_limits<int>::max()
            || result < (long long)numeric_limits<int>::min()) {
            return 0;
        }

        return (int)result;
    }
};


int main() {
    Solution s;

    cout << s.reverseInteger(123) << endl;
    cout << s.reverseInteger(-123) << endl;
    return 0;
}
