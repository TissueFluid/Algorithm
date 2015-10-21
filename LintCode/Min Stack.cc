// Min Stack

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
    stack<int> s;
    stack<int> mins;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        auto size = this->s.size();

        s.push(number);

        if (size == 0) {
            mins.push(number);
        } else {
            mins.push(std::min(number, mins.top()));
        }
    }

    int pop() {
        int ret = s.top();
        s.pop();
        mins.pop();
        return ret;
    }

    int min() {
        return mins.top();
    }
};
