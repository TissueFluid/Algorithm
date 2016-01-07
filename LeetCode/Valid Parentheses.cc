#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> m = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (const auto &ch : s) {
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
