// Minimum Window Substring

// | ------------>      找到符合的
//        |------>      缩小范围
//        |-----------> 继续找
//              |-----> 缩小范围 结果取min

#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        const int len_source = source.length();
        const int len_target = target.length();

        if (len_target == 0 || len_source == 0) {
            return "";
        }

        int occurence[256];

        memset(occurence, 0, sizeof(occurence));

        int n_target = 0;
        for (char ch : target) {
            occurence[ch]++;
            n_target++;
        }

        int lenMinStr = numeric_limits<int>::max();
        string minStr("");

        int left = 0;
        int n_source = 0;
        for (int i = 0; i < len_source; ++i) {
            if (occurence[source[i]] > 0) {
                n_source++;
            }
            occurence[source[i]]--;

            while (n_source >= n_target) {
                if (i - left + 1 < lenMinStr) {
                    lenMinStr = i - left + 1;
                    minStr = source.substr(left, lenMinStr);
                }

                occurence[source[left]]++;

                if (occurence[source[left]] > 0) {
                    n_source--;
                }
                left++;
            }
        }

        return minStr;
    }
};
