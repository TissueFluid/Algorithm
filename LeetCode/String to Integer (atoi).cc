#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        int end = str.length() - 1;

        while (start <= end) {
            if (str[start] != ' ') {
                break;
            }
            start++;
        }

        while (start <= end) {
            if (str[end] != ' ') {
                break;
            }
            end--;
        }

        if (start > end) {
            return 0;
        }

        bool positive = true;

        switch (str[start]) {
        case '-':
            positive = false;
        case '+':
            start++;
            if (start > end) {
                return 0;
            }
            break;
        }

        for (int i = start; i <= end; ++i) {
            if (!isdigit(str[i])) {
                end = i - 1;
            }
        }

        if (start > end) {
            return 0;
        }

        if (end - start + 1 > 10) {
            if (positive) {
                return numeric_limits<int>::max();
            } else {
                return numeric_limits<int>::min();
            }
        }

        long long result = 0;

        for (int i = start; i <= end; ++i) {
            result = result * 10 + str[i] - '0';
        }

        if (!positive) {
            result = -result;
        }

        if (result > numeric_limits<int>::max()) {
            return numeric_limits<int>::max();
        } else if (result < numeric_limits<int>::min()) {
            return numeric_limits<int>::min();
        } else {
            return (int)result;
        }
    }
};
