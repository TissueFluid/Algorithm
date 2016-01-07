#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
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

        int index = 0;
        string result("");

        while (num > 0) {
            int times = num / nums[index].value;
            for (int i = 0; i < times; ++i) {
                result += nums[index].symbol;
            }
            num = num % nums[index].value;
            index++;
        }

        return result;
    }
};
