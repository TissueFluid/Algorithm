// Pow(x, n)  O(log(n))


class Solution {
private:
    double pow(double x, int n) {
        if (n == 1) {
            return x;
        }

        if (n % 2 == 0) {
            double v = pow(x, n / 2);
            return v * v;
        } else {
            double v = pow(x, (n - 1) / 2);
            return v * v * x;
        }
    }
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        double retval; 
        if (n == 0) {
            retval = 1;
        }

        if (n > 0) {
            retval = pow(x, n);
        }

        if (n < 0) {
            retval = 1 / (pow(x, -n));
        }

        return retval;
    }
};
