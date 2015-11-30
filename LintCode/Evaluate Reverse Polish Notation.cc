// Evaluate Reverse Polish Notation - Stack

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    static bool isOperator(const string &op) {
        if (op.length() == 1) {
            switch (op[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
            }
        }
        return false;
    }
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> value;

        for (const auto &token : tokens) {
            if (!isOperator(token)) {
                value.push(stoi(token));
            } else {
                if (value.size() < 2) {
                    return -1;
                }

                int b = value.top();
                value.pop();
                int a = value.top();
                value.pop();

                switch(token[0]) {
                case '+':
                    value.push(a + b);
                    break;
                case '-':
                    value.push(a - b);
                    break;
                case '*':
                    value.push(a * b);
                    break;
                case '/':
                    value.push(a / b);
                    break;
                }
            }
        }

        if (value.size() == 1) {
            return value.top();
        } else {
            return -1;
        }
    }
};
