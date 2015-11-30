// Convert Expression to Polish Notation

// similar to convertToRPN
// reverse
// process
// reverse

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
private:
    static bool isOp(const string &item) {
        static const string ops = "+-*/()";

        return item.length() == 1 && ops.find(item[0]) != string::npos;
    }
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &expression) {
        reverse(expression.begin(), expression.end());

        vector<string> result;
        unordered_map<string, int> priority = {
            {"+", 1},
            {"-", 1},
            {"*", 2},
            {"/", 2},
            {")", 0}
        };

        stack<string> s_ops;

        for (const auto &item : expression) {
            if (isOp(item)) {
                if (item == ")") {
                    s_ops.push(item);
                } else if (item == "(") {
                    while (s_ops.top() != ")") {
                        result.push_back(s_ops.top());
                        s_ops.pop();
                    }
                    s_ops.pop();
                } else {
                    while (!s_ops.empty()
                           && priority[item] < priority[s_ops.top()]) {
                        result.push_back(s_ops.top());
                        s_ops.pop();
                    }
                    s_ops.push(item);
                }
            } else {
                result.push_back(item);
            }
        }

        while (!s_ops.empty()) {
            result.push_back(s_ops.top());
            s_ops.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> arg = {
        "3",
        "+",
        "5",
        "*",
        "2"
    };

    auto res = s.convertToPN(arg);

    for (const auto &item : res) {
        cout << item << endl;
    }
    return 0;
}
