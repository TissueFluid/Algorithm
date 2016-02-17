// Generate Parentheses

#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void helper(int left, int right, vector<string> &result) {
        static string tmp("");

        if (left == 0 && right == 0) {
            result.push_back(tmp);
            return;
        }

        if (left > 0) {
            tmp.push_back('(');
            helper(left - 1, right, result);
            tmp.pop_back();
        }

        if (right > left && right > 0) {
            tmp.push_back(')');
            helper(left, right - 1, result);
            tmp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(n, n, result);

        return result;
    }
};
