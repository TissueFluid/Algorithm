// Digit Counts

#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        int count = 0;
        int base = 1;

        while (n / base) {
            int current = n / base % 10;
            int higher = n / base / 10;
            int lower = n % base;

            if (current < k) {
                count += higher * base;
            } else if (current == k) {
                count += higher * base + lower + 1;
            } else {
                if (!(k == 0 && higher == 0)) {
                    count += (higher + 1) * base;
                }
            }
            base *= 10;
        }

        return count;
    }

};

int main(int argc, char *argv[])
{
    Solution s;

    cout << s.digitCounts(1, 22) << endl;
    cout << s.digitCounts(0, 10) << endl;

    return 0;
}
