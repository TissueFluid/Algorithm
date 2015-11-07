// Sort Letters by Case

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        const int len = letters.length();

        int start = 0;
        int end = len - 1;

        while (start < end) {
            while (islower(letters[start])) {
                start++;
            }
            while (isupper(letters[end])) {
                end--;
            }
            if (start < end) {
                swap(letters[start], letters[end]);
                start++;
                end--;
            }
        }
    }
};
