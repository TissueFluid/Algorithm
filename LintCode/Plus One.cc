// Plus One

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        const int size = digits.size();

        if (size == 0) {
            return {1};
        }

        reverse(digits.begin(), digits.end());

        for (int i = 0; i < size; ++i) {
            digits[i]++;
            if (digits[i] == 10) {
                digits[i] = 0;
                if (i == size - 1) {
                    digits.push_back(1);
                }
            } else {
                break;
            }
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};
