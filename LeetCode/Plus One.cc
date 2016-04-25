// Plus One

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        bool allNines = true;

        for (const auto &item : digits) {
            if (item != 9) {
                allNines = false;
                break;
            }
        }

        if (allNines) {
            result.resize(digits.size() + 1);
            result[0] = 1;
        } else {
            result.resize(digits.size());
        }

        int c = 1;
        int i, j;
        for (i = result.size() - 1, j = digits.size() - 1; c && j >= 0; --i, --j) {
            result[i] = digits[j] + c;
            if (result[i] > 9) {
                result[i] -= 10;
            } else {
                c = 0;
            }
        }

        for (; j >= 0; --i, --j) {
            result[i] = digits[j];
        }

        return result;
    }
};
