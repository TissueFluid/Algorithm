// Count and Say

#include <string>
using namespace std;

class Solution {
    string process(string target) {
        target += '#';
        string result("");
        const int LEN = target.length();

        char last = target[0];
        int count = 1;

        for (int i = 1; i < LEN; ++i) {
            if (target[i] == last) {
                count++;
            } else {
                result += to_string(count) + last;
                last = target[i];
                count = 1;
            }
        }

        return result;
    }
public:
    string countAndSay(int n) {
        string initial = "1";

        for (int i = 1; i < n; ++i) {
            initial = process(initial);
        }

        return initial;
    }
};
