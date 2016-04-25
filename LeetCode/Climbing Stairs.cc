// Climbing Stairs

class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        int c = 0;

        while (n--) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};
