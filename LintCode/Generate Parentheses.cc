// Generate Parentheses

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void generate(int n_left, int n_right, vector<string> &result) {
        static string tmp("");

        if (n_left == 0 && n_right == 0) {
            result.push_back(tmp);
            return;
        }

        if (n_left > 0) {
            tmp.push_back('(');
            generate(n_left - 1, n_right, result);
            tmp.pop_back();
        }

        if (n_left < n_right && n_right > 0) {
            tmp.push_back(')');
            generate(n_left, n_right - 1, result);
            tmp.pop_back();
        }
    }

public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        generate(n, n, result);

        return result;
    }
};
