// Coins in a Line

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        return n % 3 != 0;
    }
};
