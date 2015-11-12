// Count and Say

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        if (n <= 0) {
            return string("");
        }

        if (n == 1) {
            return string("1");
        }

        string result("1");
        for (int i = 2; i <= n; ++i) {
            string tmp("");

            int len = result.length();
            for (int j = 0; j < len; ++j) {
                int count = 1;
                char candidate = result[j];
                while (j + 1 < len && result[j + 1] == candidate) {
                    j++;
                    count++;
                }
                tmp += (to_string(count) + candidate);
            }

            result = tmp;
        }

        return result;
    }
};

int main() {
    Solution s;

    cout << s.countAndSay(5) << endl;
    return 0;
}
