// Expression Tree Build

#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <unordered_map>
#include <string>
using namespace std;

class ExpressionTreeNode {
public:
    string symbol;
    ExpressionTreeNode *left, *right;
    ExpressionTreeNode(string symbol) {
        this->symbol = symbol;
        this->left = this->right = NULL;
    }
};

class Solution {
    static bool isOp(const string &item) {
        static const string ops = "+-*/()";

        if (item.length() == 1) {
            return ops.find(item[0]) != string::npos;
        }

        return false;
    }

    static int priority(const string &item) {
        static const unordered_map<string, int> priority = {
            {"+", 1},
            {"-", 1},
            {"*", 2},
            {"/", 2},
            {"(", 0}
        };

        auto found = priority.find(item);

        if (found == priority.end()) {
            return numeric_limits<int>::max();
        } else {
            return found->second;
        }
    }

    void popOneOpWithTwoResults(stack<ExpressionTreeNode *> &result,
                               stack<ExpressionTreeNode *> &op) {
        auto root = op.top(); op.pop();

        root->right = result.top(); result.pop();
        root->left = result.top(); result.pop();
        result.push(root);
    }

public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        stack<ExpressionTreeNode *> s;
        stack<ExpressionTreeNode *> op;

        for (const auto &item : expression) {
            auto node = new ExpressionTreeNode(item);
            if (isOp(item)) {
                if (item == "(") {
                    op.push(node);
                } else if (item == ")") {
                    while (op.top()->symbol != "(") {
                        popOneOpWithTwoResults(s, op);
                    }
                    op.pop();
                } else {
                    while (!op.empty()
                        && priority(item) <= priority(op.top()->symbol)) {
                        popOneOpWithTwoResults(s, op);
                    }
                    op.push(node);
                }
            } else {
                s.push(node);
            }
        }

        while (!op.empty()) {
            popOneOpWithTwoResults(s, op);
        }

        if (s.empty()) {
            return NULL;
        } else {
            return s.top();
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> expression = {
        "3",
        "+",
        "5"
    };
    s.build(expression);
    return 0;
}
