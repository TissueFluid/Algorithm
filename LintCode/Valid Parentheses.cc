// Valid Parentheses

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> stk;

        for (const char ch : s) {
            switch (ch) {
            case '(':
            case '{':
            case '[':
                stk.push(ch);
                break;

            case ')':
            case ']':
            case '}':
                if (stk.empty() || stk.top() != m[ch]) {
                    return false;
                } else {
                    stk.pop();
                }
                break;
            }
        }

        return stk.empty();
    }
};
