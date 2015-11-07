// Print Numbers by Recursion - Recurrsion

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    void helper(int n, int last_size, vector<int> &result) {
        if (n == 0) {
            return;
        }

        const int size = result.size();

        if (size == 0) {
            for (int i = 1; i < 10; ++i) {
                result.push_back(i);
            }
        } else {
            for (int i = last_size; i < size; ++i) {
                int tmp = result[i] * 10;
                for (int j = 0; j < 10; ++j) {
                    result.push_back(tmp + j);
                }
            }
        }

        helper(n - 1, size, result);
    }
    vector<int> numbersByRecursion(int n) {
        vector<int> result;

        if (n <= 0) {
            return result;
        }

        helper(n, 0, result);

        return result;
    }
};

int main() {
    Solution s;

    auto result = s.numbersByRecursion(2);

    for (const auto &item : result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
