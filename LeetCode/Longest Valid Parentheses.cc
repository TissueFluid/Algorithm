// Longest Valid Parentheses

// init:
//   start = 0         (start index)
//
// s[i] ->
//   case '(': push to stack
//   case ')': if stk.emtpy()
//             then
//               start = i + 1
//             else
//               stk.pop()
//               res = max(res, i - index of previous '(')  if stk empty
//                     max(res, i - start + 1)              if !stk empty

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        const int LEN = s.length();
        stack<int> stk;
        int res = 0;
        int start = 0;

        for (int i = 0; i < LEN; ++i) {
            switch (s[i]) {
            case '(':
                stk.push(i);
                break;
            case ')':
                if (stk.empty()) {
                    start = i + 1;
                } else {
                    stk.pop();
                    if (stk.empty()) {
                        res = max(res, i - start + 1);
                    } else {
                        res = max(res, i - stk.top());
                    }
                }
            default:
                break;
            }
        }

        return res;
    }
};
