#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int size = strs.size();

        if (size == 0) {
            return "";
        }

        if (size == 1) {
            return strs[0];
        }

        int common = 0;
        for (; true; common++) {
            for (int j = 0; j < size; ++j) {
                if (common >= strs[j].length()
                    || strs[j][common] != strs[0][common]) {
                    return strs[0].substr(0, common);
                }
            }
        }

        return "";
    }
};
