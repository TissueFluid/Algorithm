// Implement Queue by Two Stacks

#include <stack>
#include <iostream>

using namespace std;

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        stack1.push(element);
    }

    void adjust() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

    int pop() {
        this->adjust();
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

    int top() {
        this->adjust();
        return stack2.top();
    }
};
