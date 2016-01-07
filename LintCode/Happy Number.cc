#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        int nextn;
        unordered_set<int> results;

        if (n <= 0) {
            return false;
        }

        while (1) {
            nextn = 0;
            results.insert(n);

            while (n) {
                nextn += (n % 10) * (n % 10);
                n /= 10;
            }

            if (nextn == 1) {
                return true;
            }
            if (results.find(nextn) != results.end()) {
                return false;
            }
            n = nextn;
        }

        return true;
    }
};
