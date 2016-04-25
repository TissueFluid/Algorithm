// Pow(x, n)

class Solution {
private:
    double helper(double x, unsigned long long n) {
        if (n == 1) {
            return x;
        }

        double tmp = helper(x, n / 2);
        double retval = tmp * tmp;
        if (n % 2 == 1) {
            retval *= x;
        }

        return retval;
    }
public:
    double myPow(double x, int n) {
        double retval;

        if (n == 0) {
            retval = 1;
        } else if (n < 0) {
            retval = 1.0 / helper(x, -n);
        } else {
            retval = helper(x, n);
        }

        return retval;
    }
};
