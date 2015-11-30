// Expression Evaluation

// pay attention to the [] condition

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
private:
    static bool isOp(const string &item) {
        static const string ops = "+-*/()";

        return item.length() == 1 && ops.find(item[0]) != string::npos;
    }

    static void popOneOpAndCalculate(stack<int> &nums,
                                   stack<string> &ops) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        switch (ops.top()[0]) {
        case '+':
            nums.push(a + b);
            break;
        case '-':
            nums.push(a - b);
            break;
        case '*':
            nums.push(a * b);
            break;
        case '/':
            nums.push(a / b);
            break;
        }
        ops.pop();
    }
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        stack<int> nums;
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
                        popOneOpAndCalculate(nums, ops);
                    }
                    ops.pop();
                } else {
                    while (!ops.empty()
                           && priority[item] <= priority[ops.top()]) {
                        popOneOpAndCalculate(nums, ops);
                    }
                    ops.push(item);
                }
            } else {
                nums.push(stoi(item));
            }
        }

        while (!ops.empty()) {
            popOneOpAndCalculate(nums, ops);
        }

        if (nums.empty()) {
            return 0;
        } else {
            return nums.top();
        }
    }
};
