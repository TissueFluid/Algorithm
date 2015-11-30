// Convert Expression to Reverse Polish Notation

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
private:
    static bool isOp(const string &item) {
        static const string ops = "+-*/()";

        return (item.length() == 1 && ops.find(item[0]) != string::npos);
    }
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> result;
        stack<string> ops;
        unordered_map<string, int> priority = {
            {"+", 1},
            {"-", 1},
            {"*", 2},
            {"/", 2},
            {"(", 0}
        };

        for (const auto &item : expression) {
            if (isOp(item)) {
                if (item == "(") {
                    ops.push(item);
                } else if (item == ")") {
                    while (ops.top() != "(") {
                        result.push_back(ops.top());
                        ops.pop();
                    }
                    ops.pop();
                } else {
                    while (!ops.empty()
                           && priority[item] <= priority[ops.top()]) {
                        result.push_back(ops.top());
                        ops.pop();
                    }
                    ops.push(item);
                }
            } else {
                result.push_back(item);
            }
        }

        while (!ops.empty()) {
            result.push_back(ops.top());
            ops.pop();
        }

        return result;
    }
};
