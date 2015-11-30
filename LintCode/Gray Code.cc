// Gray Code

// 00
// 01
// 11
// 10

//  00
//  01
//  11
//  10
// 110
// 111
// 101
// 100

// 1 concatenated with grayCode[n - 1].reverse()

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void helper(int n, vector<int> &result) {
        if (n == 0) {
            result.push_back(0);
            return;
        }

        helper(n - 1, result);

        const int size_result = result.size();

        for (int i = size_result - 1; i >= 0; --i) {
            result.push_back((1 << (n - 1)) + result[i]);
        }
    }
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        vector<int> result;

        helper(n, result);
        return result;
    }
};

int main() {
    Solution s;

    auto res = s.grayCode(1);

    for (const auto &item : res) {
        cout << item << endl;
    }
    return 0;
}
