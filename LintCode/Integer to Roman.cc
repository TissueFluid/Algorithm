// Integer to Roman

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        if (n <= 0) {
            return "";
        }

        struct {
            int value;
            string symbol;
        } nums[] = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string result("");

        int numPos = 0;

        while (n > 0) {
            int times = n / nums[numPos].value;

            for (int i = 0; i < times; ++i) {
                n -= nums[numPos].value;
                result += nums[numPos].symbol;
            }
            numPos++;
        }

        return result;
    }
};
