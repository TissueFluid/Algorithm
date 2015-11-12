// Unique Characters

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        int a[300] = {0};

        for (char ch : str) {
            a[ch]++;
            if (a[ch] > 1) {
                return false;
            }
        }

        return true;
    }
};
