// Multiply Strings

#include <string>
using namespace std;

class Solution {
private:
    string multiplySingleDigit(string num, char digit) {
        digit -= '0';

        if (digit == 0) {
            return "0";
        }

        char c = 0;
        const int LEN = num.length();

        for (int i = LEN - 1; i >= 0; --i) {
            int tmp = (num[i] - '0') * digit + c;
            c = tmp / 10;
            num[i] = tmp % 10 + '0';
        }

        if (c > 0) {
            num = char(c + '0') + num;
        }

        return num;
    }

    string add(string num1, string num2) {
        if (num1.length() < num2.length()) {
            swap(num2, num1);
        }

        if (num2 == "0") {
            return num1;
        }

        const int LEN1 = num1.length();
        const int LEN2 = num2.length();

        int i = LEN2 - 1;
        int j = LEN1 - 1;
        int c = 0;

        for ( ; i >= 0; --i, --j) {
            int tmp = num1[j] - '0' + num2[i] - '0' +  c;
            c = tmp / 10;
            num1[j] = tmp % 10 + '0';
        }

        for ( ; j >= 0; --j) {
            int tmp = num1[j] - '0' + c;
            c = tmp / 10;
            num1[j] = tmp % 10 + '0';
        }

        if (c > 0) {
            num1 = char(c + '0') + num1;
        }

        return num1;
    }

public:
    string multiply(string num1, string num2) {
        string result("0");

        const int LEN2 = num2.length();

        for (int i = LEN2 - 1; i >= 0; i--) {
            string tmp = multiplySingleDigit(num1, num2[i]);
            if (tmp != "0") {
                tmp += string(LEN2 - 1 - i, '0');
            }
            result = add(result, tmp);
        }


        return result;
    }
};
